#include <iostream>
#include <array>
#include <queue>
#include "grid_common.h"

template <unsigned long _ROWS, unsigned long _COLS>
bool is_valid_pos(std::array<std::array<int, _COLS>, _ROWS>& grid, const Pos& p)
{
    return (p.x >= 0 and p.x < grid.size() and
            p.y >= 0 and p.y < grid[0].size());
}

/**
 * From a given starting position, color neighbors (recursively) with opposite color
 * Assume only colors 1 and 0.  If grid[start.x][start.y] == 0, then you must write 1
 *
 * Simple, happy breadth first traversal :-)
 */
template <unsigned long _ROWS, unsigned long _COLS>
void spread_color(std::array<std::array<int, _COLS>, _ROWS>& grid, const Pos& start)
{
    std::queue<Pos> q;
    const int color = (grid[start.x][start.y] == 0) ? 1 : 0;
    static const std::array<Pos, 4> adj ={ {{-1, 0}, {1, 0}, {0, -1}, {0, 1}} };

    q.push(start);

    while (not q.empty()) {
        Pos p = q.front();
        q.pop();
        grid[p.x][p.y] = color;

        // Find eligible neighbors where color can be spread
        for (auto& _adj: adj) {
            Pos p_adj = {p.x + _adj.x, p.y + _adj.y}; // adjacent candidate
            if (is_valid_pos(grid, p_adj) and grid[p_adj.x][p_adj.y] != color) {
                q.push(p_adj);
            }
        }
    }
}


int main()
{
    std::array<std::array<int, 4>, 4> grid = {
        {
            {0, 0, 0, 1},
            {1, 0, 1, 0},
            {1, 0, 1, 0},
            {0, 1, 1, 0}
        }
    };

    Pos start = {1, 0};

    print_grid(grid);
    std::cout << "start = (" << start.x << "," << start.y << ")"  << std::endl;
    spread_color<4, 4>(grid, start);
    print_grid(grid);

    return 0;
}
