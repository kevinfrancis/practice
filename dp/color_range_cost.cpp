#include <iostream>
#include <vector>
#include <map>
#include <limits>

typedef struct {
	int first;
	int last;
	double cost;
} Triple;

typedef struct {
	std::map<int, double> *adj_map;
	double least_cost;
} AdjacentCosts;

void print_cost_map(std::map<int, AdjacentCosts*>& cost_map)
{
	std::map<int, AdjacentCosts*>::reverse_iterator it;
	for (it = cost_map.rbegin(); it != cost_map.rend(); it++) {
		std::cout << "cost_map[" << it->first << "]: ";
		AdjacentCosts *adj_costs = it->second;
		std::map<int, double>& adj_map = *(adj_costs->adj_map);
		std::map<int, double>::reverse_iterator adj_it;
		for (adj_it = adj_map.rbegin(); adj_it != adj_map.rend(); adj_it++) {
			std::cout << "(" << adj_it->first  << ", " << adj_it->second << ") ";
		}
		std:: cout << "  Least Cost to dest = " << adj_costs->least_cost;
		std::cout << std::endl;
	}
}

void build_cost_map(int first, int last, std::vector<Triple>& triples,
					std::map<int, AdjacentCosts*>& cost_map)
{
	// Build cost_map
	std::vector<Triple>::iterator it;
	for (it = triples.begin(); it != triples.end(); it++) {

		AdjacentCosts *adj_costs_ptr;

		std::map<int, AdjacentCosts*>::iterator cost_map_it = cost_map.find(it->first);
		if (cost_map_it == cost_map.end()) {
			adj_costs_ptr = new AdjacentCosts();
			adj_costs_ptr->adj_map = new std::map<int, double>();
			cost_map[it->first] = adj_costs_ptr;
			adj_costs_ptr->least_cost = std::numeric_limits<double>::infinity();
		} else {
			adj_costs_ptr = cost_map_it->second;
		}

		std::map<int, double>& adj_map = *(adj_costs_ptr->adj_map);
		std::map<int, double>::iterator adj_map_it = adj_map.find(it->last);
		if (adj_map_it == adj_map.end()) {
			adj_map[it->last] = it->cost;
		} else {
			adj_map[it->last] = std::min(adj_map[it->last], it->cost);
		}
		if (it->last == last) {
			//adj_costs_ptr->least_cost = std::min(adj_costs_ptr->least_cost,
			//									 it->cost);
		}
	}
}

void solve(int first, int last, std::vector<Triple>& triples,
		   std::map<int, AdjacentCosts*>& cost_map)
{
	std::map<int, AdjacentCosts*>::reverse_iterator it;
	for (it = cost_map.rbegin(); it != cost_map.rend(); it++) {
		int f = it->first;
		AdjacentCosts *adj_costs_ptr = it->second;
		std::map<int, double>& adj_map = *(adj_costs_ptr->adj_map);
		std::map<int, double>::reverse_iterator adj_it;
		for (adj_it = adj_map.rbegin(); adj_it != adj_map.rend(); adj_it++) {
			int l = adj_it->first;
			double cost = adj_it->second;
			if (l == last) {
				adj_costs_ptr->least_cost = std::min(adj_costs_ptr->least_cost,
													 cost);
			}
		}
	}
}


int min_cost(int first, int last, std::vector<Triple>& triples)
{
	std::map<int, AdjacentCosts*> cost_map; // Key=first, Value=NeighborCost

	build_cost_map(first, last, triples, cost_map);
	print_cost_map(cost_map);

	solve(first, last, triples, cost_map);

	return -1;
}

int main()
{
	int first = 0;
	int last = 5;
	//Triple arr[] = {{0, 5, 10}, {0, 4, 1}, {0, 2, 5}, {2, 5, 1}};
	Triple arr[] = {{0, 5, 10}, {0, 2, 1}, {2, 3, 1}, {3, 4, 1}, {4, 5, 1}};
	std::vector<Triple> triples(arr, arr + sizeof(arr)/sizeof(arr[0]));

	std::cout << "min_cost = " << min_cost(first, last, triples) << std::endl;
	return 0;
}
