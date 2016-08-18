#include <iostream>

/**
 *  Read next integer from string, starting from the given offset
 *  Update offset to new position
 *  If offset is already the end of the string, then return negative
 */
int read_int(const char* s, int& offset)
{
	// If we have already reached end of character, return negative number
	if (s[offset] == '\0') {
		return -1;
	}

	int num = 0;

	while (s[offset] != '.' && s[offset] != '\0') {
		num *= 10;
		num += s[offset] - '0';
		offset++;
	}

	if (s[offset] == '.') {
		offset++;
	}

	return num;
}

/**
 * Compare two software versions
 * e.g. 1.0.10  >  1.0.1
 *      1.0     >  1
 *      2.3     >  1.4.5
 */
int version_compare(const char* a, const char* b)
{
	int a_offset = 0, b_offset = 0;

	while (true) {

		int a_num = read_int(a, a_offset);
		int b_num = read_int(b, b_offset);

		// Equal
		if (a_num < 0 && b_num < 0)
			return 0;

		// a > b
		if (a_num > b_num)
			return 1;

		// a < b
		if (a_num < b_num)
			return -1;
	}
}

int main(int argc, char* argv[])
{
	if (argc < 3) {
		std::cerr << "insufficient args" << std::endl;
		return -1;
	}

	int result = version_compare(argv[1], argv[2]);

	std::cout << "result = " << result << std::endl;

	return 0;
}
