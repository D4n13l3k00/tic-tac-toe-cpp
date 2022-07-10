dynamic:
	mkdir -p build
	g++ main.cpp req/*.cpp -o build/ttt

static:
	mkdir -p build
	g++ -static -static-libgcc -static-libstdc++ main.cpp req/*.cpp -o build/ttt_static