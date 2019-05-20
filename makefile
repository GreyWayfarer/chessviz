all: bin/chess bin/chess-test

bin/chess: build/main.o build/printboard.o build/board.o
	gcc -Wall -Werror build/main.o build/printboard.o build/board.o -o bin/chess

build/printboard.o: build/src/printboard.c
	gcc -Wall -Werror -c build/src/printboard.c -o build/printboard.o

build/board.o: build/src/board.c
	gcc -Wall -Werror -c build/src/board.c -o build/board.o

build/main.o: build/src/main.c
	gcc -Wall -Werror -c build/src/main.c -o build/main.o

bin/chess-test: build/test/main.o build/test/board_test.o build/src/board.o build/src/printboard.o
	gcc -Wall -Werror build/test/main.o build/test/board_test.o build/src/board.o build/src/printboard.o -o bin/chess-test

build/test/main.o: test/main.c
	gcc -I thirdparty -Wall -Werror -c test/main.c -o build/test/main.o

build/test/board_test.o: test/board_test.c
	gcc -I thirdparty -Wall -Werror -c test/board_test.c -o build/test/board_test.o


.PHONY: clean
clean: build/*.o
	rm -rf build/*.o
