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
#include <climits>
#include <queue>
#include <stack>
#include <numeric>
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
    TreeNode* helper(TreeNode* root , int val){
        if (!root) return nullptr;
        if (root->val == val){ //ถ้าเจอ
            return root; //return root เพราะ โจท Treenode*
        }
        if (root->val > val){ // data มัน sort มากับ Tree ถ้าเจอน้อยกว่าเเสดงว่าอยู่ ซ้าย
            return helper(root->left , val); //ใช้ return helper เพื่อเป็นการเก็บผลลัพในรอบของ recursion นั้นๆ
        }else return helper(root->right , val);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return helper(root,val);
    }
};

class Solution { //เเบบ lterative + stack  Runtime 0 ms , Mem 79.78 %
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return nullptr;
        stack<TreeNode*> Boss;
        Boss.push(root);
        while (!Boss.empty()){
            TreeNode* Ans = Boss.top(); 
            Boss.pop();
            if (Ans->val == val){
                return Ans; // return ans cuz we use ans as our "Root" not the regular "root" of fn 
            }
            if (Ans->right) Boss.push(Ans->right); //check first if is it nullptr
            if (Ans->left) Boss.push(Ans->left); //check nullptr first
        }
        return nullptr;
    }
};