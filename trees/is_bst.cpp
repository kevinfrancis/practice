#include <iostream>

/**
 * Generic BST implementation
 */
template <class T, class Comparator>
class BstNode {
private:
	Comparator comparator;
public:
	BstNode(T x): data(x) {
		left = NULL;
		right = NULL;
	}
	BstNode* left;
	BstNode* right;
	T data;

	void insert(T value) {
		BstNode* node = this;
		while (true) {
			if (comparator(value, node->data) <= 0) {
				if (node->left == NULL) {
					node->left = new BstNode(value);
					break;
				}
				node = node->left;
			} else {
				if (node->right == NULL) {
					node->right = new BstNode(value);
					break;
				}
				node = node->right;
			}
		}
	}

	void print_inorder() {
		if (left)
			left->print_inorder();
		std::cout << data << " ";
		if (right)
			right->print_inorder();
	}

	bool is_bst()
	{
		return is_bst(NULL, NULL);
	}


private:
	/**
	 * Check if node's value is within interval
	 * If min is NULL, it is to be treated as least value in type T  (- infinity)
	 * If max is NULL, it is to be treated as greatest value in type T (+ infinity)
	 */
	bool is_bst(const T* min, const T* max)
	{
		bool min_check = true, max_check = true;

		if (min) {
			min_check = comparator(*min, data) < 0;
			std::cout << data << " > " << *min << ": " << min_check << std::endl;
		}
		
		if (max) {
			max_check = comparator(data, *max) <= 0; 
			std::cout << data << " <= " << *max << ": " << max_check << std::endl;
		}
		
		if (min_check == false or max_check == false) {
			std::cout << data << " is not within range" << std::endl;
			return false;
		}

		if (left && (left->is_bst(min, &data) == false))
			return false;

		if (right && (right->is_bst(&data, max) == false))
			return false;

		return true;
	}

};

/**
 * A generic comparator
 */
template <class T>
class GenericComparator {
public:
	int operator()(const T& left, const T& right) {
		if (left < right)
			return -1;

		if (left > right)
			return 1;

		return 0;
	}
};


int main()
{
	BstNode< int, GenericComparator<int> > root(5);

	root.insert(3);
	root.insert(8);
	root.insert(2);
	root.insert(4);
	root.insert(7);
	root.insert(9);
	root.insert(6);
	root.insert(1);
	root.insert(1);
	root.insert(9);

	root.print_inorder();
	std::cout << std::endl;

	std::cout << root.is_bst() << std::endl;

	return 0;
}
