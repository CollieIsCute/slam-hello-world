all:
	g++ -std=c++20 main.cpp lib/*.cpp -o main.elf
clean:
	@rm -rf main.elf
