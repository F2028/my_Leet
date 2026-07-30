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
    int minDepth(TreeNode* root) {
        if (root == nullptr){   //check if root == null
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr){   // if leaf + 1
            return 1;
        }
        if (root->left == nullptr && root->right != nullptr){   // if liner +1 at right number of nodes
                return 1 + minDepth(root->right);
        } 
        else if (root->right == nullptr && root->left != nullptr){  // if liner + 1 at left number of nodes
            return 1 + minDepth(root->left);
        }
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        return 1 + min(left , right);
    }
};