OS = $(shell uname)
MAC = Darwin
CC = g++


ifeq ($(OS),Linux)
	LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o a 
endif
ifeq ($(OS),Darwin)
	LIBS = `pkg-config --libs --cflags raylib` 
endif

all:
	$(CC) main.cpp $(LIBS) && ./a
draw:
	$(CC) draw.cpp $(LIBS) && ./a
clean:
	rm -rf a
