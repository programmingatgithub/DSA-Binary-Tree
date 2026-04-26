/*

Given the root of a binary tree, your task is to find the diameter of the binary tree.

The diameter (also called the width) of a binary tree is defined 
as the number of edges on the longest path between any two leaf nodes.
 Note that this path may or may not pass through the root of the tree.
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
        left = NULL;
        right = NULL;
    }
};


class Solution {
     private:
    int height(Node* root) {
        if(root == NULL){
            return -1;
        }
        int left = height(root -> left);
        int right = height ( root -> right);
        int ans = max(left, right) + 1;
        return ans;
        
        
    }
  public:
    int diameter(Node* root) {
        if (root == NULL){
            return 0;
        }
        
        int opt1 = diameter (root -> left);
        int opt2 = diameter(root -> right);
        int opt3 = height(root->left) + height(root->right) + 2;
        
        
        int ans= max(opt1 , max(opt2,opt3));
        return ans;

        
    }
};