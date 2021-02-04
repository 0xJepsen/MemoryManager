CC=gcc
FILES=Driver.c MemoryManager.c
OUT_EXE = Homework_One
all: $(FILES)
	$(CC) -o $(OUT_EXE) $(FILES)
clean:
	rm -f $(OUT_EXE)
package:
	tar --ignore-failed-read --warning=no-failed-read -cvzf $(name) *.c *.h *.txt Makefile
