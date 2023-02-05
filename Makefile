.PHONY = build

build:
	gcc -O2 -Wall -c gifdec.c
	gcc -O2 -Wall -c example.c