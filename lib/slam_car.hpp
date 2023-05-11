#ifndef __SLAM_CAR_HPP__
#define __SLAM_CAR_HPP__

#include "map2d.hpp"
#include <vector>
using Coordinate = std::pair<int, int>;

class Slam_car {
private:
	Map2d map2d;
	// milliseconds
	const int SLEEP_TIME;
	const int SEARCH_WIDTH;
	std::vector<Coordinate> bias_list;

public:
	// search_width must be a positive odd number
	Slam_car(int sleep_time = 1000, int search_width = 3);
	void dfs(const Coordinate& coordinate, const Map2d& global_map);
	void print_map();
};

#endif // !__SLAM_CAR_HPP__