#
# Example python script to generate a BOM from a KiCad generic netlist
#
# Example: Sorted and Grouped CSV BOM
#

"""
    @package
    Generate a Tab delimited list (csv file type).
    Components are sorted by ref and grouped by value with same footprint
    Fields are (if exist)
    'Ref', 'Qnty', 'Value', 'Cmp name', 'Footprint', 'Description', 'Vendor'

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

out.writerow(['Component Count:', len(net.components)])
out.writerow(['Designator', 'Value', 'Q', 'Package', 'Cmp name', 'Footprint', 'Description', 'Vendor'])

# Get all of the components in groups of matching parts + values
# (see ky_generic_netlist_reader.py)
grouped = net.groupComponents()

# Output all of the component information
for group in grouped:
    refs = ""

    # Add the reference of every component in the group and keep a reference
    # to the component so that the other data can be filled in once per group
    for component in group:
        refs += component.getRef() + ", "
        c = component

    # Fill in the component groups common data
    out.writerow([refs, c.getValue(), len(group), "", c.getPartName(), c.getFootprint(),
        c.getDescription(), c.getField("Vendor")])
