CC=g++
FLAGS=-g -std=c++17
SOURCE=*.cpp
TARGET=-o main
LIBS=
all:
	$(CC) $(FLAGS) $(SOURCE) $(TARGET) $(LIBS)
