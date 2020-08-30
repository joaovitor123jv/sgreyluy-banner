CC=gcc

EXE_NAME=banner

SOURCE_FILES=src/main.c


all:
	$(CC) -o $(EXE_NAME) $(SOURCE_FILES)

debug:
	$(CC) -g -Wall -o $(EXE_NAME) $(SOURCE_FILES)
	valgrind ./$(EXE_NAME)
