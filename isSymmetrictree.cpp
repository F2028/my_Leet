#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
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

    bool Helper(TreeNode* left , TreeNode* right){
        if (left == nullptr && right == nullptr){
            return true;
        }
        if (left == nullptr || right == nullptr){
            return false;
        }
        return left->val == right->val && Helper(left->left , right ->right) && Helper(right->left , left->right);
    }
        bool isSymmetric(TreeNode* root) {

        return Helper(root->left,root->right);
    }
};