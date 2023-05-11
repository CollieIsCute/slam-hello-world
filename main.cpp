#include "lib/map2d.hpp"
#include "lib/slam_car.hpp"
#include <random>

const int SLEEP_TIME = 100;

int main() {
	std::mt19937 gen32(std::random_device{}());
	Map2d global_map("global_map.txt");
	Slam_car sc = Slam_car(SLEEP_TIME, 3);
	sc.dfs({gen32() % global_map.size(), gen32() % global_map[0].size()},
		   global_map);
}