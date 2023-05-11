#ifndef __MAP2D_HPP__
#define __MAP2D_HPP__

#include <vector>
#include <string>

class Map2d{
private:
	std::vector<std::vector<char>> map2d;

public:
    Map2d() = default;
	Map2d(const std::string& filename);
	char search(std::pair<int, int> coordinate);
	void print();
	size_t size() const;
	void push_back(const std::vector<char>& row);
	std::vector<char>& operator[](int index);
	const std::vector<char>& operator[](int index) const;
};

#endif // !__MAP2D_HPP__
