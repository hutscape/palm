#
# Example python script to generate a BOM from a KiCad generic netlist
#
# Example: Sorted and Grouped CSV BOM
#

"""
    @package
    Generate a Tab delimited list (csv file type).
    Components are sorted by ref and grouped by value with same footprint

    Spreadsheet columns include:
    'Designator', 'Value', 'Q', 'Package', 'Category', 'Stock', 'Manufacturer', 'Manufacturer Part No. (Datasheet)', 'Vendor (Vendor link)', 'Unit cost', 'Total cost', 'Minimum Order', 'Description'

    Command line:
    python "bom.py" *.xml bill_of_materials.csv
"""

import kicad_netlist_reader
import csv
import sys

try:
    f = open(sys.argv[2], 'w')
except IOError:
    e = "Can't open output file for writing: " + sys.argv[2]
    print(__file__, ":", e, sys.stderr)
    f = sys.stdout

net = kicad_netlist_reader.netlist(sys.argv[1])
out = csv.writer(f, lineterminator='\n', delimiter=',', quotechar='\"', quoting=csv.QUOTE_ALL)

out.writerow([
    'Designator',
    'Value',
    'Q',
    'Package',
    'Category',
    'Stock',
    'Manufacturer',
    'Manufacturer Part No. (Datasheet)',
    'Vendor (Vendor link)',
    'Unit cost',
    'Total cost',
    'Minimum Order',
    'Description'
])

# Get all of the components in groups of matching parts + values
# (see ky_generic_netlist_reader.py)
grouped = net.groupComponents()
grand_total = 0.0

def total_cost(unit_cost, quantity, maximum):
    if not unit_cost:
        return 0

    return float(unit_cost) * max(int(quantity), int(maximum))

def get_datasheet_part_no(datasheet, part_no):
    if datasheet == "~": # datasheet link is empty
        if not part_no:
            return ""
        else:
            return part_no
    else:
        if not part_no:
            return "=HYPERLINK(\"" + datasheet + "\", \"" + "Link to datasheet" + "\")"
        else:
            return "=HYPERLINK(\"" + datasheet + "\", \"" + part_no + "\")"

def get_vendor_link(vendor_name, vendor_link):
    if not vendor_name:
        if vendor_link:
            return "=HYPERLINK(\"" + vendor_link + "\", \"" + "Please put the vendor name according to this link" + "\")"
        else:
            return ""
    else:
        if vendor_link:
            return "=HYPERLINK(\"" + vendor_link + "\", \"" + vendor_name + "\")"
        else:
            return vendor_name

# Output all of the component information
for group in grouped:
    refs = ""

    # Add the reference of every component in the group and keep a reference
    # to the component so that the other data can be filled in once per group
    for component in group:
        refs += component.getRef() + ", "
        c = component

    # Fill in the component groups common data
    out.writerow([
        refs,
        c.getValue(),
        len(group),
        c.getField("Package"),
        c.getField("Category"),
        c.getField("Stock"),
        c.getField("Manufacturer"),
        get_datasheet_part_no(c.getDatasheet(), c.getField("Part No.")),
        get_vendor_link(c.getField("Vendor"), c.getField("Vendor link")),
        c.getField("Unit cost"),
        total_cost(c.getField("Unit cost"), len(group), c.getField("Minimum Order")),
        c.getField("Minimum Order"),
        c.getPartName() + ": " + c.getDescription()
    ])

    grand_total += total_cost(c.getField("Unit cost"), len(group), c.getField("Minimum Order"))

out.writerow([
    'Total:',
    len(net.groupComponents()),
    len(net.components),
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    format(grand_total, '.2f'),
    "",
    "",
])
