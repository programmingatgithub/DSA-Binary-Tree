
/*Given a binary tree root[],
you need to find the sum of the nodes on the longest path from the root to any leaf node.
If two or more paths have the same length, 
the path with the maximum sum of node values should be considered.

*/

#include <iostream>
using namespace std;
class Solution {
  public:
  
  void solve(Node* root ,int sum ,int &maxsum ,int len ,int &maxlen ){
      // base case 
      if( root == NULL ){
          if( len > maxlen){
              maxlen = len ;
              maxsum = sum ;
              
          } else if(len == maxlen)
          {
              maxsum = max(sum , maxsum);
          }
          return;
      }
      
      sum = sum + root->data;
      
      solve (root -> left , sum , maxsum,len+1,maxlen);
      solve(root -> right , sum , maxsum , len+1 , maxlen);
  }
    int sumOfLongRootToLeafPath(Node *root) {
        int len = 0;
        int maxlen = 0;
        
        int sum = 0;
        int maxsum = INT_MIN;
        
        solve (root,sum,maxsum,len, maxlen);
        
        return maxsum;
        
    }
};