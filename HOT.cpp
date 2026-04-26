/* 
Given the root of a binary tree, your task is to find the maximum depth of the tree.

Note: The maximum depth or height of the tree is the number of edges in the tree from the root to the deepest node.
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    int height(Node *root) {
        if (!root) return -1; \

        int leftDepth = height(root->left);
        int rightDepth = height(root->right);

        return 1 + max(leftDepth, rightDepth);
    }
};