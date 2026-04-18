/*Given a binary tree of size  n, a node, and a positive integer k.,
 Your task is to complete the function kthAncestor(), 
 the function should return the kth ancestor of the given node in the binary tree.
  If there does not exist any such ancestor then return -1.
Note:
1. It is guaranteed that the node exists in the tree.
2. All the nodes of the tree have distinct values.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    Node* solve(Node* root, int &k, int node) {
        if (root == NULL) return NULL;

        if (root->data == node) return root;

        Node* left = solve(root->left, k, node);
        Node* right = solve(root->right, k, node);

        if (left != NULL || right != NULL) {
            k--;
            if (k == 0) return root;
            return (left != NULL) ? left : right;
        }

        return NULL;
    }

    int kthAncestor(Node *root, int k, int node) {
        Node* ans = solve(root, k, node);
        if (ans == NULL || ans->data == node) return -1;
        return ans->data;
    }
};