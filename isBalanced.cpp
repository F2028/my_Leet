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
struct Result {
    bool balanced;
    int height;
};
class Solution {
public:
        Result checkHeight (TreeNode* root){
                if (root == nullptr){
                    return Result{true , 0 };
                }
                Result left = checkHeight(root->left);  //ลงไปให้ลึกสุด เเล้ว return ค่ากลับมา [bool,int]
                Result right = checkHeight(root->right);

                bool balance = left.balanced == true && right.balanced == true && abs(left.height - right.height) <= 1; //
                int height = 1 + max(left.height , right.height);   //จะทำก็ต่อเมื่อรู้ค่า
               return Result {balance,height};

        }

    bool isBalanced(TreeNode* root) {
        Result balance = checkHeight(root);
        return balance.balanced;
    }
};