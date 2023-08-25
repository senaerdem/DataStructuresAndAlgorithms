all: build run

build:
	g++ -I ./include/ -o ./lib/Stack.o -c ./src/Stack.cpp
	g++ -I ./include/ -o ./lib/BST.o -c ./src/BST.cpp
	g++ -I ./include/ -o ./lib/LinkedList.o -c ./src/LinkedList.cpp
	g++ -I ./include/ -o ./lib/Utilities.o -c ./src/Utilities.cpp
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./bin/main ./lib/Stack.o ./lib/Utilities.o ./lib/Node.o ./lib/BST.o ./lib/LinkedList.o ./src/main.cpp

run:
	./bin/main
