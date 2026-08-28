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
#include <sstream>    
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
    int helper(TreeNode* root){
        if (root == nullptr) return 0;
        int result = 0;
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr){
            result = root->left->val;
            return result + helper(root->right);
        }
        return helper(root->left) + helper(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root);
    }
};