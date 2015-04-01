CC	=g++
BIN	=./bin/
SRC	=./src/
MAIN	=main
LIB	=-lboost_system -lboost_filesystem

.PHONY:clean
all:iMCs01.o arduino.o joystick.o main.o main

iMCs01.o:$(SRC)iMCs01.cpp
	$(CC) -c $< -o $(BIN)$@ $(LIB)

arduino.o:$(SRC)arduino.cpp
	$(CC) -c $< -o $(BIN)$@ $(LIB)

joystick.o:$(SRC)joystick.cpp
	$(CC) -c $< -o $(BIN)$@ $(LIB)

main.o:$(SRC)main.cpp
	$(CC) -c $< -o $(BIN)$@ $(LIB)

main:main.o joystick.o
	$(CC) $(BIN)main.o $(BIN)joystick.o $(BIN)arduino.o $(BIN)iMCs01.o -o $@ $(LIB)
clean:
	rm $(BIN)iMCs01.o $(BIN)arduino.o $(BIN)joystick.o $(BIN)main.o main
