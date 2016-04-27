#include <iostream>
#include <vector>

std::vector<std::pair <int, std::string> > decimal_roman_pairs;

std::string decimal_to_roman(int x)
{
    //Allocate enough space for largest expected (3999: mmmcmxcxix)
    char* roman = new char[12];
    int pos = 0;

    std::vector<std::pair <int, std::string> >::iterator it;
    for (it = decimal_roman_pairs.begin(); it != decimal_roman_pairs.end(); it++) {

        if (!(x > 0))
            break;

        int value = it->first;

        if (x >= value) {
            std::string symbols = it->second; // Symbol to write

            int count = x / value;  // Number of times to repeat the symbol

            for (; count; count--) {
                // write symbols to roman for count times
                std::string::iterator sym_it;
                for (sym_it = symbols.begin(); sym_it != symbols.end(); sym_it++) {
                    roman[pos++] = *sym_it;
                }
            }
            x = x % value; // To be processed next
        }
    }

    roman[pos++] = '\0'; // Set last char to 0
    return roman;
}

void _insert_dec_roman_pair(int value, std::string symbol)
{
    decimal_roman_pairs.push_back(std::make_pair(value, symbol));
}

void init_decimal_roman_pairs()
{
    _insert_dec_roman_pair(1000, "m");
    _insert_dec_roman_pair(900, "cm");
    _insert_dec_roman_pair(500,  "d");
    _insert_dec_roman_pair(400, "cd");
    _insert_dec_roman_pair(100,  "c");
    _insert_dec_roman_pair(90,  "xc");
    _insert_dec_roman_pair(50,   "l");
    _insert_dec_roman_pair(40,  "xl");
    _insert_dec_roman_pair(10,   "x");
    _insert_dec_roman_pair(9,   "ix");
    _insert_dec_roman_pair(5,    "v");
    _insert_dec_roman_pair(4,   "iv");
    _insert_dec_roman_pair(1,    "i");
}

int main(int argc, char* argv[])
{
    init_decimal_roman_pairs();
    std::cout << decimal_to_roman(std::stoi(argv[1])) << std::endl;
}
