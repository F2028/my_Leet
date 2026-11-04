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
    void helper(TreeNode* root , int mini , int& secon){ // หาตัวที่ 2 ที่น้อยที่สุด
        if (!root) return;
        if (root->val > mini){ // ถ้าค่าปัจจุบันของ node มากกว่า mini
            if (secon == -1 or root->val < secon){ //ทำ
                //ถ้า second คือ-1 หรือ ค่าปัจจุบันของ node น้อยกว่า second
                secon = root->val; //ให้secon = ค่าของnodeปัจจุบันเพราะ mini คือค่าที่น้อยที่สุดอยู่เเล้ว
            } 
            return; // return เพราะลูกและลูกหลานของ Node นี้ไม่มีทางมีค่าน้อยกว่า Node ปัจจุบัน
            //เพราะโจทกำหมดมาให้ root.val = min(root.left.val, root.right.val)
        }
            helper(root->left, mini , secon);
            helper(root->right,  mini , secon);
    }
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        int mini = root->val;
        int second = -1;
        helper(root,mini,second);
        return second;
    }
};