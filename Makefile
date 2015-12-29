SRC=src/main.c src/testlibrary.c
HEADER=header/testlibrary.h


all: src/*c
	gcc $^ -Iheader -o gameoflife -lm -std=gnu99 -lpthread

testcase: src/main.c src/testlibrary.c src/matrix.c src/gameoflife.c
	gcc src/main.c src/testlibrary.c src/matrix.c src/gameoflife.c -Iheader -o testcase -lm -D'TEST' -std=gnu99 -lpthread

