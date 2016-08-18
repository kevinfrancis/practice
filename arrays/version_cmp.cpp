#include <iostream>

/**
 * Read next integer starting from ptr
 * Move pointer as the integer is being read
 */
int read_int(char const **ptr)
{
	// If we have already reached end of character, return negative number
	if (**ptr == '\0') {
		return -1;
	}

	int num = 0;

	while (**ptr != '.' && **ptr != '\0') {
		num *= 10;
		num += **ptr - '0';
		(*ptr)++;
	}

	if (**ptr == '.') {
		(*ptr)++;
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
	char const **a_ptr = &a;
	char const **b_ptr = &b;

	while (true) {

		int a_num = read_int(a_ptr);
		int b_num = read_int(b_ptr);

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
