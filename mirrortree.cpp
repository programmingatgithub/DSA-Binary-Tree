/*
Given the root of a binary tree, convert the binary tree to its Mirror tree.

Note: Mirror of a Binary Tree ,
T is another Binary Tree M(T) with left and right children of all non-leaf nodes interchanged.
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
        left = right = NULL;
    }
};


class Solution {
  public:
    void mirror(Node* root) {
       if(!root) return ;
        
        mirror(root -> left);
        mirror(root -> right);
        
        // swap 
        swap(root->left , root -> right);
        
       
        
        
    }
};