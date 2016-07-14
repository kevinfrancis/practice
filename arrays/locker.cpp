#include <iostream>
#include <queue>
#include <array>
#include <climits>
#include <algorithm>

/**
 * Given a list of co-ordinates of Amazon lockers in a 2-D array (or grid)
 * Fill the grid such that each slot has the distance to the nearest locker.
 * distance is calculated by traversing horizontal or vertical only.
 */


void print_grid(std::vector< std::vector<int> >& grid)
{
	for (auto& row: grid) {
		for (auto& value: row) {
			std::cout << value << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
}


void add_neighbors(int num_rows, int num_cols,
				   int x, int y,
				   std::vector<int>& neighbor_xs, std::vector<int>& neighbor_ys)
{
	std::vector<int> xs = {x,     x, x-1, x+1};
	std::vector<int> ys = {y-1, y+1,   y,   y};

	for (int i = 0; i < xs.size(); i++) {
		int neighbor_x = xs[i];
		int neighbor_y = ys[i];

		if (neighbor_x >= 0 && neighbor_x < num_rows &&
			neighbor_y >= 0 && neighbor_y < num_cols) {

			neighbor_xs.push_back(neighbor_x);
			neighbor_ys.push_back(neighbor_y);
		}
	}
}

std::vector< std::vector<int> >&
get_locker_distance_grid(int num_rows, int num_cols,
						 std::vector<int>& x_coordinates,
						 std::vector<int>& y_coordinates)
{
	/* Create grid and initialize all values to Max Integer */
	auto& grid = *(new std::vector< std::vector<int> >);

	for (int i = 0; i < num_rows; i++) {
		auto &row = *(new std::vector<int>);
		for (int j = 0; j < num_cols; j++) {
			row.push_back(INT_MAX);
		}
		grid.push_back(row);
	}

	std::vector<int> xs;
	std::vector<int> ys;

	/* Adjust x & y coordinates so that indexes start from 0 */
	for (auto& x: x_coordinates)  xs.push_back(x - 1);
	for (auto& y: y_coordinates)  ys.push_back(y - 1);


	for (int distance = 0; xs.size() > 0; distance++) {

		std::vector<int> neighbor_xs;
		std::vector<int> neighbor_ys;

		for (int i = 0; i < xs.size(); i++) {
			int x = xs[i];
			int y = ys[i];

			if (grid[x][y] > distance) {
				std::cout << "grid[" << x << "][" << y << "] = " << distance << std::endl;
				grid[x][y] = distance;
				// Add neighbors to neighbor_xs and neighbor_ys
				add_neighbors(num_rows, num_cols, x, y, neighbor_xs, neighbor_ys);
			}
		} 

		// Swap xs with neighbor xs
		xs.swap(neighbor_xs);
		ys.swap(neighbor_ys);
	}

	return grid;
}


int main()
{
	std::vector<int> x_coordinates = {1};
	std::vector<int> y_coordinates = {1};

	auto& grid = get_locker_distance_grid(5, 3, x_coordinates, y_coordinates);

	print_grid(grid);

	return 0;
}
