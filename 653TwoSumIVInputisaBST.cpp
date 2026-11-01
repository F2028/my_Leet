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
    bool helper(TreeNode* root , int k , unordered_set<int>& A){
            if (!root) return false;
            if (A.count(k-root->val)){ //นับว่า k - root.val(ค่าของnodeปัจจุบัน)มันจะนับผล - ว่ามีเลขนั้นอยู่ไหม
                return true;
            } else A.insert(root->val); //ถ้าไม่เจอให้เก็บไว้ก่อน
           bool left = helper(root->left , k,A);
           bool right= helper(root->right,k,A);
           return left || right;
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> A;
        return helper(root,k,A);
    }
};
