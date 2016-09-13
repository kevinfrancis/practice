#ifndef __GRID_COMMON_H__
#define __GRID_COMMON_H__

struct Pos {
    int x;
    int y;
};

bool operator==(const Pos& lhs, const Pos& rhs)
{
    return (lhs.x == rhs.x and lhs.y == rhs.y);
}

template <unsigned long _rows, unsigned long _cols>
void print_grid(std::array<std::array<int, _cols>, _rows>& maze)
{
    for (auto& row: maze) {
        for (auto& val: row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}


#endif // __GRID_COMMON_H__
