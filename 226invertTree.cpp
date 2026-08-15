#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <cmath>    
using namespace std;    
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  class Solution {
  public:
    TreeNode* invertTree(TreeNode* root) {
            if(!root){
                return root;
            }
                swap(root->left,root->right);  // swap fn use to swap
                invertTree(root->left);     //we called root.left to come swap with recursion
                invertTree(root->right);    // we called root.right to come swap with recursion
            
            return root;
    }
};