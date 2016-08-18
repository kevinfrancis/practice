#include <iostream>
#include <sys/time.h>

/* 
 * Experimenting with gettimeofday
 * and calculating time delta
 */


int sum(int k)
{
	int ret = 0;

	while (k) {
		ret += k--;
	}

	return ret;
}


int main()
{
	struct timeval t1, t2;


	gettimeofday(&t1, NULL);
	int result = 0;
	for (int i = 0; i < 1000; i++) {
		result = sum(100000);
	}
	gettimeofday(&t2, NULL);

	long sec_diff = t2.tv_sec - t1.tv_sec;
	time_t microsec_diff = t2.tv_usec - t1.tv_usec;

	if (microsec_diff < 0) {
		microsec_diff += 1000000;
		sec_diff -= 1;
	}

	std::cout << "t1 = " << t1.tv_sec << ", " << t1.tv_usec << std::endl;
	std::cout << "t2 = " << t2.tv_sec << ", " << t2.tv_usec << std::endl;

	std::cout << "sec = " << sec_diff << std::endl;
	std::cout << "microsec = " << microsec_diff << std::endl;
	std::cout << "result = " << result << std::endl;
	
	return 0;

}
