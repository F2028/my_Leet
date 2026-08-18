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

    void helper(TreeNode* root , string path , vector<string>& result) {
            if (root->left == nullptr && root->right == nullptr){ // check leaf?
                result.push_back(path); // then push and return
                return;
            }
            if (root->left != nullptr){ // recursion check left 
               helper(root->left,path + "->" + to_string(root->left->val) ,result);
            
            }
            if (root->right != nullptr){    // recursion check right
             helper(root->right,path + "->" + to_string(root->right->val) ,result);
           
            }
    }


class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
         if (!root){
            return vector<string>{};
        }
        vector<string> result;
        string path = to_string(root->val);
        helper(root,path,result);
        return result;
    }
};