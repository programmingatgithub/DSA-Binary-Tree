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
  void rightview(Node* root , int level, vector<int> & ans){
      if(!root) return;
      
      // first node 
      if(level == (int)ans.size())
      ans.push_back(root->data);
      
      // traverse right first then left
      rightview(root-> right, level + 1, ans);
      rightview(root -> left , level+1, ans);
  }
    vector<int> rightView(Node *root) {
        vector<int> ans;
        rightview(root , 0 , ans);
        return ans ;
        
        
        
        
    }
};