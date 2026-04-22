#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};


class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        if(!root) return ans;
        
        map<int , int> hdmap;
        
        queue<pair<Node* , int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            Node* node = q.front().first;
            int hd = q.front().second;
            q.pop();
            
            
            hdmap[hd] = node->data;
            
            if(node->left)
            q.push({node -> left, hd - 1});
            
            if(node -> right)
            q.push({node -> right, hd + 1});
        }
        
        // traverse from left to right
        
        for(auto& p : hdmap)
        ans.push_back(p.second);
        
        
        return ans;
        
    }
};