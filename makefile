all: board.o snake.o food.o position.o array.o
	gcc -Wall ./obj/board.o ./obj/array.o ./obj/snake.o ./obj/position.o ./obj/food.o ./src/main.c -o snake -lncurses

board.o: obj
	gcc -c -o ./obj/board.o ./src/board.c

snake.o: obj
	gcc -c -o ./obj/snake.o ./src/snake.c

position.o: obj
	gcc -c -o ./obj/position.o ./src/position.c

food.o: obj
	gcc -c -o ./obj/food.o ./src/food.c

array.o: obj
	gcc -c -o ./obj/array.o ./src/array.c

obj:
	mkdir obj

build:
	docker build -t snake .

clean:
	rm -rf ./obj/*
	rm -rf ./snake

run: build
	docker run -it snake