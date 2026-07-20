CC = gcc

CFLAGS = -Wall -Wextra -std=c11 -Isrc
LIBS = -lSDL3 -lSDL3_image

all: flappy platformer

flappy:
	mkdir -p build
	$(CC) $(CFLAGS) src/Engine.c games/FlappyBird.c -o build/FlappyBird $(LIBS)

platformer:
	mkdir -p build
	$(CC) $(CFLAGS) src/Engine.c games/Platformer.c -o build/Platformer $(LIBS)

run-flappy: flappy
	./build/FlappyBird

run-platformer: platformer
	./build/Platformer

clean:
	rm -rf build
