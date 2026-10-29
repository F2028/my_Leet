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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2; // ถ้า root1 == nullptr ให้ใช้ root2 เเทน
        if (!root2) return root1; //เหมือนกันใช้ root1 เเทน
        root1->val += root2->val; //บวกค่าของ node เข้าด้วยกันไปที่ root1
        root1->left = mergeTrees(root1->left ,root2->left); //recursionเรียกข้างซ้าย - ขวา
        //อย่าลืมสร้างที่เก็บค่านะจะ
        root1->right= mergeTrees(root1->right,root2->right); //recursionเรียกข้างซ้าย - ขวา
        //อย่าลืมสร้างที่เก็บค่านะจะ
        return root1; // returnผลรวมที่เรา + เเล้วเก็บไว้
    }
};