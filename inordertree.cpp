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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
            inorder(root, result);      // recursion
            return result;
    }
    void inorder (TreeNode* root , vector<int>& result){      // func helper
            if (root == nullptr){
                return;
            }
           inorder(root->left,result);          //เรียกทางซ้ายเก็บค่า
           result.push_back(root->val);         //push ค่าตัวเองเข้าไป
           inorder(root->right,result);         ////เรียกทางขวาเก็บค่า
    }   
};