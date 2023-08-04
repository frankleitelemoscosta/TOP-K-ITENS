all:

	g++ ./src/Utils.hpp ./src/Utils.cpp ./src/Analysis.cpp ./src/Analysis.hpp ./src/Heap.hpp ./src/Heap.cpp ./src/Hash.hpp ./src/Hash.cpp ./src/main.cpp -o ./build/objects/app

clean:

	rm -rf ./build/objects/app

run:

	./build/objects/app