/*Given the root of a binary tree and an integer k, 
determine the number of downward-only paths where the sum of the node values in the path equals k.


Note: A path can start and end at any node within the tree but must always move downward 
(from parent to child).
*/

#include <iostream>
using namespace std;

class Solution {
public:
    void solve(Node* root, int k, int &count, vector<int>& path) {  // Pass by reference!
        if (root == NULL) return;
        
        path.push_back(root->data);  
        
        int sum = 0;
        for (int i = path.size() - 1; i >= 0; i--) {
            sum += path[i];
            if (sum == k) {
                count++;
            }
        }
        
       solve(root->left, k, count, path);
        solve(root->right, k, count, path);
        
        path.pop_back();  // Backtrack
    }
    
    int countAllPaths(Node* root, int k) {
        vector<int> path;
        int count = 0;
        solve(root, k, count, path);  
        return count;
    }
};