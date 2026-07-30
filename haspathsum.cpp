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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr){
            return false;
        }
        targetSum -= (root->val);   // target -= value ของ root

        if (root->left == nullptr && root->right == nullptr && targetSum == 0){ // เช็ค left เเละ target == 0
            return true;
        }
        return hasPathSum(root->left , targetSum) || hasPathSum(root->right , targetSum);   //เรียก recursion จนกว่าจะโดน base case
    }
};  