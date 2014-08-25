all: clean build upload

build:
	ino build --board-model=atmega328

upload:
	ino upload --board-model=atmega328

clean:
	ino clean
