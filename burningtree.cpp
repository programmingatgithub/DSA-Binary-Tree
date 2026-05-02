/*
Given the root of a binary tree and a target node,
 determine the minimum time required to burn the entire tree if the target node is set on fire. 
 In one second, the fire spreads from a node to its left child, right child, and parent.

*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
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
  unordered_map<int, Node*> parentmap;
  void buildparentmap(Node* root,Node* parent){
      if(!root) return;
      parentmap[root -> data] = parent;
      buildparentmap(root -> left , root);
      buildparentmap(root -> right , root);
  }
  
  Node* findtarget(Node* root , int target){
      if(!root) return nullptr;
      if(root -> data == target) return root;
      Node* left = findtarget(root-> left , target);
      return left ? left : findtarget(root -> right , target);
  }
    int minTime(Node* root, int target) {
        buildparentmap(root , nullptr);
        
        Node* firenode = findtarget(root , target);
        if(!firenode) return 0;
        
        queue<Node*> q;
        unordered_set<int> visited;
        q.push(firenode);
        visited.insert(firenode -> data);
        
        int time = 0;
        
        while(!q.empty()){
            int size = q.size();
        for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();

                // Check left child
                if (node->left && visited.find(node->left->data) == visited.end()) {
                    visited.insert(node->left->data);
                    q.push(node->left);
                }

                // Check right child
                if (node->right && visited.find(node->right->data) == visited.end()) {
                    visited.insert(node->right->data);
                    q.push(node->right);
                }

                // Check parent via parentMap
                if (parentmap[node->data] &&
                    visited.find(parentmap[node->data]->data) == visited.end()) {
                    visited.insert(parentmap[node->data]->data);
                    q.push(parentmap[node->data]);
                }
            }

            // One second has passed
            if (!q.empty())
                time++;
        }

        return time;
        

    }
};