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
        std:: cout << "  MIN_COST = " << adj_costs->least_cost << ";";
        std::map<int, double>& adj_map = *(adj_costs->adj_map);
        std::map<int, double>::reverse_iterator adj_it;
        std::cout << "   Adjacencies = [ ";
        for (adj_it = adj_map.rbegin(); adj_it != adj_map.rend(); adj_it++) {
            std::cout << "(" << adj_it->first  << "," << adj_it->second << ") ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;
}

AdjacentCosts *add_to_cost_map(std::map<int, AdjacentCosts*>& cost_map, int v)
{
    AdjacentCosts *adj_costs_ptr = new AdjacentCosts();
    adj_costs_ptr->adj_map = new std::map<int, double>();
    adj_costs_ptr->least_cost = std::numeric_limits<double>::infinity();
    cost_map[v] = adj_costs_ptr;
    return adj_costs_ptr;
}

void build_cost_map(int first, int last, std::vector<Triple>& triples,
                    std::map<int, AdjacentCosts*>& cost_map)
{
    // Build cost_map
    std::vector<Triple>::iterator it;

    add_to_cost_map(cost_map, first);
    add_to_cost_map(cost_map, last);
    

    for (it = triples.begin(); it != triples.end(); it++) {

        AdjacentCosts *adj_costs_ptr;

        std::map<int, AdjacentCosts*>::iterator cost_map_it = cost_map.find(it->first);
        if (cost_map_it == cost_map.end()) {
            // Insert triple's first if it doesn't exist
            adj_costs_ptr = add_to_cost_map(cost_map, it->first);
        } else {
            adj_costs_ptr = cost_map_it->second;
        }

        // Insert triple's last if it doesn't exist
        if (cost_map.find(it->last) == cost_map.end()) {
            add_to_cost_map(cost_map, it->last);
        }

        std::map<int, double>& adj_map = *(adj_costs_ptr->adj_map);
        std::map<int, double>::iterator adj_map_it = adj_map.find(it->last);
        if (adj_map_it == adj_map.end()) {
            adj_map[it->last] = it->cost;
        } else {
            adj_map[it->last] = std::min(adj_map[it->last], it->cost);
        }
    }
}

void solve(int first, int last, std::vector<Triple>& triples,
           std::map<int, AdjacentCosts*>& cost_map)
{
    // For each 'f' in cost_map
    std::map<int, AdjacentCosts*>::reverse_iterator it;
    for (it = cost_map.rbegin(); it != cost_map.rend(); it++) {
        int f = it->first;
        AdjacentCosts *adj_costs_ptr = it->second;
        std::map<int, double>& adj_map = *(adj_costs_ptr->adj_map);

        // For each {l, cost} in cost_map[f]
        std::map<int, double>::reverse_iterator adj_it;
        for (adj_it = adj_map.rbegin(); adj_it != adj_map.rend(); adj_it++) {
            int l = adj_it->first;
            double cost = adj_it->second;
            double my_least_cost = adj_costs_ptr->least_cost;

            if (l == last) {
                my_least_cost = std::min(my_least_cost, cost);
            } else {
                my_least_cost = std::min(my_least_cost, cost + cost_map[l]->least_cost);
            }
            adj_costs_ptr->least_cost = my_least_cost;

            // update least_cost in cost_map[k] for all f < k <= l
            // TODO:  Can interval trees help reduce time complexity here ?
            std::map<int, AdjacentCosts*>::reverse_iterator cost_map_it;
            for (cost_map_it = cost_map.rbegin();
                 (cost_map_it != cost_map.rend()) and  cost_map_it->first > f;
                 cost_map_it++) {
                if (cost_map_it->first > l)
                    continue;
                AdjacentCosts& adj_costs = *(cost_map_it->second);
                adj_costs.least_cost = std::min(my_least_cost, adj_costs.least_cost);
            }
        }
    }
}


double min_cost(int first, int last, std::vector<Triple>& triples)
{
    std::map<int, AdjacentCosts*> cost_map; // Key=first, Value=NeighborCost

    build_cost_map(first, last, triples, cost_map);
    solve(first, last, triples, cost_map);

    double result = cost_map[first]->least_cost;
    if (result == std::numeric_limits<double>::infinity()) {
        result = -1;
    }

    return result;
}

int main()
{
    int first;
    int last;
    Triple arr[] = {{0, 6, 10}, {0, 3, 1}, {1, 5, 1}, {4, 6, 1}}; first = 0; last = 6;
    //Triple arr[] = {{0, 5, 10}, {0, 4, 1}, {0, 2, 5}, {2, 5, 1}}; first = 0; last = 5;
    //Triple arr[] = {{0, 5, 10}, {0, 2, 1}, {2, 3, 1}, {3, 4, 1}, {4, 5, 1}}; first = 0; last = 5;
    //Triple arr[] = {{1, 5, 1}, {0, 6, 2}, {2, 8, 3}, {5, 10, 1}, {0, 11, 8}}; first = 0; last = 10;
    //Triple arr[] = {{0,5,10}, {0,3,1}, {3,4,2}, {3,4,1}, {4,5,1}, {0,2,5}}; first = 0; last = 5;
    //Triple arr[] = {{1,4,10}, {2,5,6}}; first = 0; last = 5;
    std::vector<Triple> triples(arr, arr + sizeof(arr)/sizeof(arr[0]));

    std::cout << "min_cost = " << min_cost(first, last, triples) << std::endl;
    return 0;
}
