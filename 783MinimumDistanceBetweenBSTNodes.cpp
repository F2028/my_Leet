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

class Solution { // ใช้ prev , mini
public:
    int prev = -1;
    int mini = INT_MAX;
    void inorder(TreeNode* root){
        if (!root) return;
        inorder(root->left);
        if (prev != -1) mini = min(mini , root->val - prev);
        //ถ้า prev มี ค่าเเล้วให้หาค่าน้อยระหว่าง = ตัวmini กับ ค่า ปัจจุบัน
        prev = root->val; // เเละ update ค่า
        inorder(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return mini;
    }
};

class Solution { // stack
public:
    int minDiffInBST(TreeNode* root) {
        int prev = -1;
        int mini = INT_MAX;
        stack<TreeNode*> A; //เก็บเป็น treenode
        TreeNode* B = root; //ใ้ช B เเทนเพราะจะไม่ยุ่งกะ root
        while (B or !A.empty()){
            while (B) { // ดันฝั่งซ้ายเข้าสุด
                A.push(B); // push ก่อนเพราะถ้าขยับจะเป็น 1 -> 2 not 0 -> 1
                B = B->left;
            }
            TreeNode* toon = A.top(); // ตั่งให้เปนตัวล่าสุดที่จะเอาไว้ pop
            A.pop();
            if (prev != -1) mini = min(mini , toon->val - prev);
            prev = toon->val;
            B = toon->right;
        }
        return mini;
    }
};

class Solution { // sample code
public:
    TreeNode* prev = NULL;
    int minDiffInBST(TreeNode* root) {
        int mini = INT_MAX;
        if (!root) return INT_MAX;
        if(root->left){
            int left = minDiffInBST(root->left);
            mini = min(mini , left);
        }
        if (prev){
            mini = min(mini , root->val - prev->val);
        }
        prev = root;
        if (root->right){
            int right = minDiffInBST(root->right);
            mini = min(mini , right);
        }
        return mini;
    }
};