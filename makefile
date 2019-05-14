all: bin/chess

bin/chess: build/main.o build/printboard.o build/board.o
	gcc -Wall -Werror build/main.o build/printboard.o build/board.o -o bin/chess

build/printboard.o: build/src/printboard.c
	gcc -Wall -Werror -c build/src/printboard.c -o build/printboard.o

build/board.o: build/src/board.c
	gcc -Wall -Werror -c build/src/board.c -o build/board.o

build/main.o: build/src/main.c
	gcc -Wall -Werror -c build/src/main.c -o build/main.o

.PHONY: clean
clean: build/*.o
	rm -rf build/*.o
