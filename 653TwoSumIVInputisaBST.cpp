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

  class Solution { //เเบบ helper recursion DFS = dept first search
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

class Solution { // lterative DSF
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        unordered_set<int> oil;
        stack<TreeNode*> jay;
        jay.push(root);
        while(!jay.empty()){
            TreeNode* cur = jay.top(); //ให้เก็บค่าตัวบนสุดก่อน .top คือตัวบนสุดของ stack
            jay.pop(); //เเล้วค่อยเอาออก
            //เพราะเราไม่ได้ทำ recursion เลยต้องทำเเบบนี้
            if (oil.count(k-cur->val)){ //ถ้าเจอเลขที่เป็นผลลบของ k-cur.val ใน oil return true
                return true;
            } else oil.insert(cur->val); //ไม่เจอก็เก็บไว้
           if(cur->left) jay.push(cur->left); //เช็คก่อนว่ามัน nullptr ไหมถ้าไม่ ดันค่า cur.left เข้า jay
           if (cur->right) jay.push(cur->right);  //เช็คก่อนว่ามัน nullptr ไหมถ้าไม่ ดันค่า cur.right เข้า jay
        }
        return false;
    }
};