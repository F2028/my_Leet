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
    int tilt = 0; //เอาไว้คำนวณผล result
    int helper (TreeNode* root){
        if (!root) return 0;
        int left = helper(root->left); //เอาค่าval left ทั้งหมดของ root
        int right = helper(root->right); // เอาค่าval right ทั้งหมดของ root
        int total = abs(left - right); // อันนี้คือผลรวม-ลบของ subT
        tilt += total; // คำนวณเช่น tilt = tilt(0) + total(2){รอบเเรก} = 2 {รอบ2} tilt(2) + total(5) = 7
        return left + right + root->val; // คืนผลรวมของ Node ทั้งหมด
    }
    int findTilt(TreeNode* root) {
         tilt = 0;
         helper(root);
         return tilt;
    }
};
// อีก solution
class Solution {
public:
    pair <int , int> helper(TreeNode* root){
        if (!root) return {0 , 0};
        pair <int , int> left = helper(root->left);
        pair <int , int> right = helper(root->right);
        int sum = left.first + right.first + root->val;
       int tile = abs(left.first - right.first) + left.second + right.second;
        return {sum , tile};
    }
    int findTilt(TreeNode* root) {
       return helper(root).second;
    }
};