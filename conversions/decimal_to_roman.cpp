#include <iostream>
#include <vector>

std::vector<std::pair <int, std::string> > decimal_roman_pairs;

std::string decimal_to_roman(int x)
{
    return "not implemented";
}

void _insert_dec_roman_pair(int value, std::string symbol)
{
    decimal_roman_pairs.push_back(std::make_pair(value, symbol));
}

void init_decimal_roman_pairs()
{
    _insert_dec_roman_pair(1000, "m");
    _insert_dec_roman_pair(1000, "m");
    _insert_dec_roman_pair(1000, "m");
    _insert_dec_roman_pair(1000, "m");
    _insert_dec_roman_pair(1000, "m");    
}

int main(int argc, char* argv[])
{
    init_decimal_roman_pairs();
    std::cout << decimal_to_roman(std::stol(argv[1])) << std::endl;
}
