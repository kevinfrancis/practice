#include <iostream>

class BinaryTreeNode {
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
};

/**
 * Find nearest common ancestor of two nodes in a binary tree
 * ==> NOT A BINARY SEARCH TREE <==
 */
BinaryTreeNode* find_nearest_common_ancestor(BinaryTreeNode* root, int x, int y)
{
    if (root == NULL or root->data == x or root->data == y) {
        return root;
    }

    BinaryTreeNode* left_result = find_nearest_common_ancestor(root->left, x, y);
    BinaryTreeNode* right_result = find_nearest_common_ancestor(root->right, x, y);

    if (left_result and right_result) {
        return root;
    }

    return (left_result ? left_result : right_result);
}


/**
 * Find nearest commaon ancestor assuming Binary Search Tree
 * ==>  IS A BINARY SEARCH TREE <===
 */
BinaryTreeNode* find_nearest_common_ancestor_bst(BinaryTreeNode* root, int x, int y)
{
    // Ensure x <= y.  Otherwise swap
    if (x > y) {
        std::swap(x, y);
    }
    
    if (root == NULL) {
        return root;
    }

    if (root->data < x) {
        return find_nearest_common_ancestor_bst(root->right, x, y);
    }

    if (root->data > y) {
        return find_nearest_common_ancestor_bst(root->left, x, y);
    }

    return root;
}

/**
 * Non-recursive version for Binary Search Tree
 */
BinaryTreeNode* find_nearest_common_ancestor_bst_non_recursive(BinaryTreeNode* root, int x, int y)
{
    if (x > y) {
        std::swap(x, y);
    }

    while (root) {
        if (root->data > y) {  // x & y are both in left sub-tree
            root = root->left;
        } else if (root->data < x) { // x & y are both in right sub-tree
            root = root->right;
        } else {
            break;
        }
    }

    return root;
}
