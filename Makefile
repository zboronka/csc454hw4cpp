CC=g++
FLAGS=-g -std=c++17
SOURCE=src/*.cpp
TARGET=-o main
LIBS=
all:
	$(CC) $(FLAGS) $(SOURCE) $(TARGET) $(LIBS)
