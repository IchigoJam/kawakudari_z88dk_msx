zcc +msx $1.c -subtype=rom -create-app -o $1.rom
openmsx -machine C-BIOS_MSX2_JP -cart $1.rom
