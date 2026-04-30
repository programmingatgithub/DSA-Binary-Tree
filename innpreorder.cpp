/*

Given two arrays representing the inorder and preorder traversals of a binary tree, 
your task is to construct the binary tree and return its root.

Note: The inorder and preorder traversals contain unique values, 
and every value present in the preorder traversal is also found in the inorder traversal.
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        unordered_map<int, int> inMap;
        int n = inorder.size();
        for (int i = 0; i < n; i++)
            inMap[inorder[i]] = i;

        int preIndex = 0;
        
        function<Node*(int, int)> helper = [&](int inLeft, int inRight) -> Node* {
            if (inLeft > inRight) return nullptr;

            int rootVal = preorder[preIndex++];
            Node* root = new Node(rootVal);

            int rootIdx = inMap[rootVal];
            root->left  = helper(inLeft, rootIdx - 1);
            root->right = helper(rootIdx + 1, inRight);

            return root;
        };

        return helper(0, n - 1);
    }
};