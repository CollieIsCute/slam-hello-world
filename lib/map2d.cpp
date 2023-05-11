#include "map2d.hpp"
#include <cassert>
#include <fstream>
#include <iostream>

Map2d::Map2d(const std::string& filename) {
	std::ifstream ifs(filename);
	std::string line;
	while(std::getline(ifs >> std::ws, line) && !line.empty()) {
		std::vector<char> row;
		for(const char& c : line)
			row.push_back(c);
		map2d.push_back(row);
	}
}

char Map2d::search(std::pair<int, int> coordinate) {
	return map2d[coordinate.first][coordinate.second];
}

void Map2d::print() {
	for(const auto& row : map2d) {
		for(const auto& pixel : row)
			std::cout << pixel << " ";
		std::cout << std::endl;
	}
}

size_t Map2d::size() const {
	return map2d.size();
}

void Map2d::push_back(const std::vector<char>& row) {
	map2d.push_back(row);
}

std::vector<char>& Map2d::operator[](int index) {
	return map2d[index];
}

const std::vector<char>& Map2d::operator[](int index) const {
	return map2d[index];
}