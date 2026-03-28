build hello_world:
	clang++ -std=c++20 -g hello_world/src/main.cpp -o hello_world/build/main

run hello_world:
	./hello_world/build/main

build grow_array:
	clang++ -std=c++20 -O0 -g -I grow_array/include grow_array/src/*.cpp -o grow_array/build/main

run grow_array:
	./grow_array/build/main