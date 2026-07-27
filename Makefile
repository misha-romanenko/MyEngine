CC = gcc

CFLAGS = -Wall -Wextra -std=c11 -Isrc
LIBS = -lSDL3 -lSDL3_image

SRC = $(wildcard src/*.c)


all: flappy platformer animation-demo




flappy:
	mkdir -p build
	$(CC) $(CFLAGS) $(SRC) src/Engine.c games/FlappyBird.c -o build/FlappyBird $(LIBS)

platformer:
	mkdir -p build
	$(CC) $(CFLAGS) $(SRC) games/Platformer.c -o build/Platformer $(LIBS)

animation-demo:
	mkdir -p build
	$(CC) $(CFLAGS) $(SRC) games/AnimationDemo.c -o build/AnimationDemo $(LIBS)

run-flappy: flappy
	./build/FlappyBird

run-platformer: platformer
	./build/Platformer

run-animation-demo: animation-demo
	./build/AnimationDemo


clean:
	rm -rf build
