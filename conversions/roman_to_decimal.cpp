#include <iostream>
#include <map>

/**
 * Convert a roman numeral to decimal
 * Assume input is a valid roman-numeral
 */

std::map<char, int> roman_value_map;

int roman_to_decimal(std::string roman)
{
    int total = 0;
    int prev_symbol_value = 0;
    
    for (int i=0; i < roman.length(); i++) {
        int value = roman_value_map[roman[i]];
        total += value;
        if (prev_symbol_value < value) {
            total -= 2 * prev_symbol_value;
        }
        prev_symbol_value = value;
    }

    return total;
}

void initialize_roman_value_map(void)
{
    roman_value_map['i'] = 1;
    roman_value_map['v'] = 5;
    roman_value_map['x'] = 10;
    roman_value_map['l'] = 50;
    roman_value_map['c'] = 100;
    roman_value_map['d'] = 500;
    roman_value_map['m'] = 1000;
}

int main(int argc, char* argv[])
{
    initialize_roman_value_map();
    std::cout << roman_to_decimal(argv[1]) << std::endl;
    return 0;
}
