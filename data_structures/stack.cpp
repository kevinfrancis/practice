#include <iostream>
#include <exception>

template <class T, unsigned int SIZE>
class Stack {
private:
	int top;
	T a[SIZE];
public:
	Stack(): top(-1) {
	}
	T pop() {
		if (top == -1) {
			throw 20;
		}
		T value = a[top];
		top--;
		return value;
	}

	void push(T value) {
		if (top == SIZE - 1) {
			throw 30;
		}
		top++;
		a[top] = value;
	}

	bool empty() {
		return (top == -1);
	}
};


int main()
{
	Stack<int, 4> s;
	try {
		for (int i = 1; i <= 4; i++)
			s.push(i);

		while (not s.empty())
			std::cout << s.pop() << std::endl;
	} catch (int& x) {
		std::cout << "exception occurred" << std::endl;
		return -1;
	}

	return 0;
}
