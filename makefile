.PHONY: run compile clean
ARGS=recipes/opposition.chef

run: main
	./main $(ARGS)

compile main: main.o parser.o
	gcc -Wall -Werror -fsanitize=address,undefined -lpcre2-8 -o main main.o parser.o

main.o: main.c parser.c parser.h
	gcc -c main.c

parser.o: parser.c parser.h
	gcc -c parser.c

clean:
	rm -f main *.o
