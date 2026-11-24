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
    void inorder(TreeNode* root , vector<int>& A){ //ทำให้ค่ามันเรียงเป็น vector
        if (!root) return;
        inorder(root->left,A);
        A.push_back(root->val);
        inorder(root->right,A);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> A;
        inorder(root,A);
        int mini = INT_MAX; // เพื่อหาค่าน้อยสุดเลยตั้งให้เป็นมากที่สุดเพราะไม่ว่ายังไงมันก็จะถูกเปลี่ยนค่า
        for (int i = 1; i < A.size();i++){
                mini = min(mini , A[i] - A[i-1]);
        }
        return mini;
    }
};