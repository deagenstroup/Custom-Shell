CC = gcc
SRC_FILES = cs4310_a4/src/shell.c
OUT_EXE = cs4310_a4/shell.exe

build: $(SRC_FILES)
	$(CC) -o $(OUT_EXE) $(SRC_FILES)
