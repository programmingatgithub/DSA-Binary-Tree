//Given a binary tree, find its reverse level order traversal. ie- the traversal must begin from the last level.


#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
}; 
class Solution {
  public:
    vector<int> reverseLevelOrder(Node *root) {
        vector <int> result;
        if(root == NULL)
        return result;
        
        vector<vector<int>> levels;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            
            for(int i = 0; i < size ; i++){
                Node* node = q.front();
                q.pop();
                
                level.push_back(node -> data);
                
                if(node -> left)
                q.push(node -> left);
                
                if(node -> right)
                q.push(node -> right);
            }
            levels.push_back(level);
            
        }
        
        for(int i = (int)levels.size() - 1; i >= 0;i--)
        for(int x : levels[i])
        result.push_back(x);
        
        
        return result;
        
        
        
    }
};