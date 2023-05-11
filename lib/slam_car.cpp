#include "slam_car.hpp"
#include "map2d.hpp"
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

namespace {
Coordinate operator+(const Coordinate& a, const Coordinate& b) {
	return {a.first + b.first, a.second + b.second};
}

bool valid_coodinate(const Map2d& m, const Coordinate& c) {

	if(c.first < 0 || c.first >= m.size())
		return false;
	if(c.second < 0 || c.second >= m[c.first].size())
		return false;
	return true;
}

void update_map(Map2d& m, const Coordinate& c, char NOT_VISITED) {
	while(m.size() <= c.first)
		m.push_back(std::vector<char>());
	while(m[c.first].size() <= c.second)
		m[c.first].push_back(NOT_VISITED);
}
}  // namespace

Slam_car::Slam_car(int sleep_time, int search_width)
	: SLEEP_TIME(sleep_time), SEARCH_WIDTH(search_width) {
	for(int i = -search_width / 2; i <= search_width / 2; i++)
		for(int j = -search_width / 2; j <= search_width / 2; j++)
			if(i || j)
				bias_list.push_back({i, j});
}

void Slam_car::dfs(const Coordinate& coordinate, const Map2d& global_map) {
	const static char NOT_VISITED = '?';
	std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
	auto not_visited = [](Map2d& m, const Coordinate& c) {
		update_map(m, c, NOT_VISITED);
		return m[c.first][c.second] == NOT_VISITED;
	};
	std::vector<Coordinate> dfs_list;
	for(const auto& i : bias_list) {
		Coordinate tmpC = coordinate + i;
		if(valid_coodinate(global_map, tmpC) && not_visited(map2d, tmpC)
		   && map2d[tmpC.first][tmpC.second] != 'X') {
			if(global_map[tmpC.first][tmpC.second] != 'X')
				dfs_list.push_back(tmpC);
			map2d[tmpC.first][tmpC.second] =
				global_map[tmpC.first][tmpC.second];
		}
	}
	std::cout << std::endl << std::endl;
	print_map();
	for(const auto& c : dfs_list)
		dfs(c, global_map);
}

void Slam_car::print_map() {
	map2d.print();
}