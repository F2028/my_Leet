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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr){
            return true;
        }
        if (p == nullptr || q == nullptr){
            return false;
        }
        return (p->val == q->val) && isSameTree(p->left , q->left) && isSameTree(p->right , q->right) ; // เปรียบเทียบ (ค่า) , ส่งค่าซ้ายของสองตัวมาเเล้วจะเปรียบเทียบกับ เองเหมือนกับฝั่งขวา
    }
};