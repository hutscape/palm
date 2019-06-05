.PHONY: bom clean

bom: clean
	python bom/bom.py hardware/Palm.xml bill_of_materials.csv

clean:
	rm -f bill_of_materials.csv
