all: build run


build:
	g++ -I ./include/ -o ./lib/Reading.o -c ./src/Reading.cpp
	g++ -I ./include/ -o ./lib/Stack.o -c ./src/Stack.cpp
	g++ -I ./include/ -o ./lib/BTS.o -c ./src/BTS.cpp
	
	
	g++ -I ./include/ -o ./bin/main ./lib/Reading.o ./lib/Stack.o  ./lib/BTS.o ./src/main.cpp

run:
	./bin/main.exe