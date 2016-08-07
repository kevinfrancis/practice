#include <iostream>
#include <map>
#include <vector>

/**
 * Read characters from a and update count in "char_count" map
 */
void populate_char_count(std::string& a, std::map<char, int>& char_count)
{
    for (std::string::iterator it  = a.begin(); it != a.end(); it++) {
        std::map<char, int>::iterator map_it = char_count.find(*it);
        if (map_it == char_count.end()) {
            char_count[*it] = 1;
        } else {
            ++map_it->second; // just increment value
        }
    }
}

/**
 * Copy char_count from "from_map" to "to_map"
 */
void copy_char_count(const std::map<char, int>& from_map, std::map<char, int>& to_map)
{
    for (std::map<char, int>::const_iterator it = from_map.begin(); it != from_map.end(); ++it) {
        to_map[it->first] = it->second;
    }
}

/**
 * Find all permutations of string a inside string s
 *
 * @param s  string
 * @param a  string
 * @return   List of indices in s
 */
std::vector<int> find_permutations(std::string s, std::string a)
{
    std::map<char, int> char_count;     // Character count in string a
    populate_char_count(a, char_count);    
    std::map<char, int> win_char_count(char_count); // copy construct fom char_count
    std::vector<int> locations; // List of locations where permutation of a was found

    // a is larger than s.  No perm of a can fit inside s
    if (a.size() > s.size()) {
        return locations;
    }

    int window_start = 0;

    for (int i = 0; i < s.size(); i++) {
        if (char_count[s[i]] > 0) { // character present in a
            --win_char_count[s[i]]; // include s[i] in win_char_count

            // Preserve invariant win_char_count[c] >= 0 for any c
            if (win_char_count[s[i]] < 0) { // too many occurrences in s than in a
                for (int &j = window_start; s[j] != s[i]; ++j) {
                    ++win_char_count[s[j]];  // Pop s[j] from win_char_count
                }
            }
            
            // Window length has reached a's length
            if (i - window_start + 1 == a.size()) {
                if (win_char_count[s[i]] == 0) {
                    locations.push_back(window_start);
                }
                
                // Pop s[window_start]
                ++win_char_count[s[window_start]];
                ++window_start;
            }

        } else { // char not present in a
            // reset window
            window_start = i + 1;
            copy_char_count(char_count, win_char_count);
        }
    }

    return locations;
}

void print_locations(std::string& s, int length, const std::vector<int> &locations)
{
    for (std::vector<int>::const_iterator it = locations.begin(); it != locations.end(); it++) {
        std::string sub_str(s, *it, length);
        std::cout << "Location: " << *it << " substring: " << sub_str << std::endl;
    }
}

int main(int argc, char* argv[])
{
    std::string s(argv[1]);
    std::string a(argv[2]);
    
    std::vector<int> locations = find_permutations(s, a);
    print_locations(s, a.size(), locations);
    
    return 0;
}
