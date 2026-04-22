#include <iostream>
using namespace std;
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> result ;
        if(root == NULL)
        return result;
        
        queue<Node*> q;
        q.push(root);
        
        bool lefttoright = true; // flag
        
        while(!q.empty()){
            int size = q.size();
            vector<int> ans(size) ;
            for(int i = 0; i < size ; i++){
                Node* frontnode = q.front();
                q.pop();
                
                int index = lefttoright ? i : size - i - 1;
                ans[index] = frontnode -> data;
                
                if(frontnode -> left)
                q.push(frontnode -> left);
                
                  if(frontnode -> right)
                q.push(frontnode -> right);
                
            
            }
            lefttoright = !lefttoright;
            
            for (auto i : ans){
                result.push_back(i);
            }
        }
        return result;
    }
};