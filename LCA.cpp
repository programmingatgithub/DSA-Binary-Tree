/*Given the root of a binary tree with all unique values and two nodes value, n1 and n2.
 Your task is to find the lowest common ancestor of the given two nodes.
  Both node values are always present in the Binary Tree.

Note: LCA is the first common ancestor of both the nodes n1 and n2 from bottom of tree.*/


#include <iostream>
using namespace std;
class Solution {
  public:
    Node* lca(Node* root, int n1, int n2) {
        //base case
        if (root == NULL){
            return NULL;
        }
        if(root -> data == n1 ||root-> data == n2)
        {
            return root;
        }
        Node* leftans = lca(root ->left , n1 ,n2);
        Node* rightans = lca(root -> right , n1 ,n2);
        
        if(leftans != NULL && rightans != NULL){
            return root;
        }
        else if(leftans != NULL && rightans == NULL)
            return leftans;
        
        else if (leftans == NULL && rightans != NULL)
            return rightans;
        
        else
            return NULL;
        
            
        
        
    }
};