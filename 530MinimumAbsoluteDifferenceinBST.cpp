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
    void inorder(TreeNode* root , vector<int>& res){ // ถ้าอยากส่งเป็น parameterให้เป็นตัวเดียวกันทำ &
      // recusion หา inorder
      if (root == nullptr) return;
        inorder(root->left , res);
        res.push_back(root->val);
        inorder(root->right , res);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> result;
        inorder(root , result);
        int j = 1;
        int mini = INT_MAX;
        mini = result[j] - result[j-1];// สร้าง mini ก่อน
    while (j < result.size()){ //ตอนเเรกใช้ for เเต่ต้องสร้าง mini นอก loopก่อนเพราะเราต้องใช้ถ้าสร้างinloop มันจะเปลี่ยนค่าเรื่อยๆ
            if ( result[j] - result[j-1] < mini){ // เเล้วค่อยหาถ้า mini น้อยกว่าค่าเดิมที่เดินยุ
            mini = min(mini ,result[j] - result[j-1]);
            }
            j++;
      }
      return mini;
    }
};