all: build run

build:
	g++ -I ./include/ -o ./lib/AverageCalculator.o -c ./src/AverageCalculator.cpp
	g++ -I ./include/ -o ./lib/FileParser.o -c ./src/FileParser.cpp
	g++ -I ./include/ -o ./lib/LinkedList.o -c ./src/LinkedList.cpp
	g++ -I ./include/ -o ./bin/main ./lib/AverageCalculator.o ./lib/FileParser.o ./lib/LinkedList.o ./src/main.cpp

run:
	./bin/main
