all:

	g++ ./src/Utils.hpp ./src/Utils.cpp ./src/Heap.hpp ./src/Heap.cpp ./src/Hash.hpp ./src/Hash.cpp ./src/main.cpp ./src/StopWords.hpp ./src/StopWords.cpp -o ./build/objects/app

clean:

	rm -rf ./build/objects/app

run:

	./build/objects/app