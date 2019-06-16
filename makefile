all: bin/chess bin/chess-test

bin/chess: build/main.o build/printboard.o build/board.o
	gcc -Wall -Werror build/main.o build/printboard.o build/board.o -o bin/chess

build/printboard.o: src/printboard.c
	gcc -Wall -Werror -c src/printboard.c -o build/printboard.o

build/board.o:src/board.c
	gcc -Wall -Werror -c src/board.c -o build/board.o

build/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o

bin/chess-test: build/main_test.o build/board_test.o build/board.o build/printboard.o
	gcc -Wall -Werror build/main_test.o build/board_test.o build/board.o build/printboard.o -o bin/chess-test

build/main_test.o: test/main.c
	gcc -I thirdparty -Wall -Werror -c test/main.c -o build/main_test.o

build/board_test.o: test/board_test.c
	gcc -I thirdparty -Wall -Werror -c test/board_test.c -o build/board_test.o


.PHONY: clean
clean: build/*.o
	rm -rf build/*.o
