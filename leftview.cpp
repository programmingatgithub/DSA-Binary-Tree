#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
  public:
  void leftview (Node* root , int level , vector<int> &ans){
      if(!root) return;
      
      //First Node
      if(level == (int)ans.size())
      ans.push_back(root->data);
      
      leftview(root->left , level + 1 , ans);
      leftview(root->right , level + 1, ans);
      
  }
    vector<int> leftView(Node *root) {
        vector<int> ans;
        leftview(root, 0 , ans);
        return ans;
        
    }
};