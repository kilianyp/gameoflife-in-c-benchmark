SRC=src/main.c src/testlibrary.c
HEADER=header/testlibrary.h


all: src/main.c
	gcc src/main.c -o gameoflife -lm

testcase: src/main.c src/testlibrary.c
	gcc src/main.c src/testlibrary.c -Iheader -o testcase -lm -D'TEST'

