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
    vector<int> topView(Node *root) {
        vector<int> ans;
        if(root == NULL)
        return ans;
        
        // Horizontal distance 
        map<int, int> hdmap;
        
        queue<pair<Node*,int>> q;
        q.push({root , 0});
        
        while (!q.empty()){
            Node* node = q.front().first;
            int hd = q.front().second;
            q.pop();
            
            if(hdmap.find(hd) == hdmap.end())
            hdmap[hd] = node->data;
            
            if(node -> left)
            q.push({node-> left , hd - 1});
            
            if(node -> right)
            q.push({node -> right , hd + 1});
            
            
            
            
        }
        
        // traverse from leftmost to rightmost
        for (auto& p : hdmap)
        ans.push_back(p.second);
        
        
       return ans ;
        
    
    }
};