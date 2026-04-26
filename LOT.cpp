 //Given the root of a Binary Tree, your task is to return its Level Order Traversal.
 
 #include <iostream>
 using namespace std;
 

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
  public:
    vector<int> levelOrder(Node *root) {
        vector<int> result;
        if(!root) return result;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            
            result.push_back(node -> data);
            
            if(node -> left)
            q.push(node -> left);
            
            if(node -> right)
            q.push(node -> right);
        }
        
        return result;
        
        
    }
};