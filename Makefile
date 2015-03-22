CC	=g++
MAIN	=main
LIB	=-lboost_system -lboost_filesystem

.PHONY:clean
all:main.o main

main.o:main.cpp
	$(CC) -c $< -o $@ $(LIB)

main:main.o
	$(CC) $< -o $@ $(LIB)
clean:
	rm main.o main
