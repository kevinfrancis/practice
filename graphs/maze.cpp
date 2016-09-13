#include <iostream>
#include <vector>
#include <array>
#include "grid_common.h"

/**
 * Maze solver
 * 0 is traversable
 * 1 is not traversable
 * Given a start coordinate & end coordinate (both 0s), find if a path exists from start to end
 * Uses DFS
 */
template <unsigned long _rows, unsigned long _cols>
std::vector<Pos> solve_maze(std::array< std::array<int, _cols>, _rows>& maze, const Pos& start, const Pos& end)
{
    std::vector<Pos> path;
    _solve_maze(maze, start, end, path);
    return path;
}

template <unsigned long _rows, unsigned long _cols>
bool is_valid_pos(std::array< std::array<int, _cols> , _rows>& maze, const Pos& p)
{
    return (p.x >= 0 and p.x < maze.size() and
            p.y >= 0 and p.y < maze[0].size() and
            maze[p.x][p.y] == 0); // not visited
}

/**
 * Core of the maze-solver algorithm
 */
template <unsigned long _rows, unsigned long _cols>
static bool _solve_maze(std::array< std::array<int, _cols>, _rows>& maze, const Pos& start, const Pos& end,
                        std::vector<Pos>& path)
{
    maze[start.x][start.y] = 1;  // Mark as visited
    path.push_back(start);

    // Reached end
    if (start == end) {
        maze[start.x][start.y] = 0;  // Undo visited mark
        return true;
    }

    static const std::array<Pos, 4> adjust = {{{0, -1}, {0, 1}, {-1, 0}, {1, 0}}};

    for (auto& _adj: adjust) {
        Pos new_start = {start.x + _adj.x, start.y + _adj.y};
        if (is_valid_pos(maze, new_start)) {
            if (_solve_maze<_rows, _cols>(maze, new_start, end, path) == true) {
                maze[start.x][start.y] = 0;  // Undo visited mark
                return true;
            }
        }
    }

    path.pop_back();
    maze[start.x][start.y] = 0;
    return false;
}

void print_path(std::vector<Pos>& path)
{
    for (auto& pos: path) {
        std::cout << "(" << pos.x << "," << pos.y << ") ";
    }
    std::cout << std::endl;
}

int main()
{
    std::array<std::array<int, 4>, 4> maze = {
        {
            {0, 0, 0, 0},
            {1, 0, 1, 1},
            {1, 0, 0, 1},
            {1, 1, 0, 0}
        }
    };
    
    print_grid<4, 4>(maze);

    std::vector<Pos> path = solve_maze<4, 4>(maze, {0,0}, {3,3});
    print_path(path);

    std::vector<Pos> path2 = solve_maze<4, 4>(maze, {0, 0}, {0, 0});
    print_path(path2);
    
    return 0;
}
