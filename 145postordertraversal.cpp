#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
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
    void helper (TreeNode* root , vector <int>& result){    //เราส่ง vector ไปเเค่เก็บค่าเฉยๆไม่จำเป็นต้องมี data           
            if (root == nullptr){
                return;
            }     
                   
             helper(root->left,result);                     // recursion เช้ค left
             helper(root->right,result);                    // recursion เช้ค right
             result.push_back(root->val);                   // เเค่เปลี่ยนที่
    }
    vector<int> postorderTraversal(TreeNode* root) {      
            vector <int> ans;   
            helper(root,ans);
            return ans;
    }
};