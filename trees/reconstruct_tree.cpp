#include <iostream>
#include <vector>

class Node {
public:
	Node *left;
	Node *right;
	int data;

	void print(void) {
		std::cout << data << ": ";
		if (left) {
			std::cout << "left = {";
			left->print();
			std::cout << "} ";
		}

		if (right) {
			std::cout << "right = {";
			right->print();
			std::cout << "} ";
		}
	}
};

// Get index of value in vector
int search_root(std::vector<int> v, int start, int len, int value)
{
	for (int i = start; i < start + len; i++) {
		if (v[i] == value) {
			return i;
		}
	}
}

Node* reconstruct_tree(std::vector<int> inorder, int inorder_start, int inorder_len,
					   std::vector<int> preorder, int preorder_start, int preorder_len)
{
	if (preorder_len == 0) {
		return NULL;
	}

	int root_value = preorder[preorder_start];

	Node* root = new Node;
	root->data = root_value;

	int inorder_pos_of_root = search_root(inorder, inorder_start, inorder_len, root_value);
	int num_left_nodes = inorder_pos_of_root - inorder_start;
	int num_right_nodes = inorder_len - (num_left_nodes + 1);

	root->left = reconstruct_tree(inorder, inorder_start, num_left_nodes,
								  preorder, preorder_start + 1, num_left_nodes);
	root->right = reconstruct_tree(inorder, inorder_start + num_left_nodes + 1, num_right_nodes,
								   preorder, preorder_start + 1 + num_left_nodes, num_right_nodes);

	return root;
}

Node* reconstruct_tree(std::vector<int> inorder, std::vector<int> preorder)
{
	return reconstruct_tree(inorder, 0, inorder.size(), preorder, 0, preorder.size());
}


int main()
{
	std::vector<int> inorder = {1, 2, 3, 4, 5};
	std::vector<int> preorder = {3, 1, 2, 4, 5};

	Node *tree = reconstruct_tree(inorder, preorder);

	if (tree) {
		tree->print();
		std::cout << std::endl;
	}

	return 0;
}
