#
# Generate netlist in XML format from inside KiCad
# Go to KiCad > Eeschema > Tools > Generate Bill of Materials
# Netlist in format *.xml will be created
#

"""
    @package
    Generate a netlist in XML format from inside KiCad
    KiCad > Eeschema > Tools > Generate Bill of Materials > Add plugin

"""

import kicad_netlist_reader
import csv
import sys

net = kicad_netlist_reader.netlist(sys.argv[1])
