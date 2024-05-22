.PHONY: run compile clean

run: main
	./main

compile main: main.o
	gcc -o main main.o

main.o: main.c
	gcc -c main.c

clean:
	rm -f main *.o
