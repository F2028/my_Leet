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
    void helperiorder (TreeNode* root , vector<int>& inorder){ //เรียงลำดับ inorder
        if (root == nullptr) return;
        helperiorder(root->left, inorder); // recursion เรียก root ซ้าย
        inorder.push_back(root->val);
        helperiorder(root->right, inorder); // ขวา
    }
    vector<int> findMode(TreeNode* root) { // หา
        vector<int> inorder; //สร้าง vector
        helperiorder(root , inorder); // do recursion inorder
        int maxs = INT_MIN; //เก็บค่าที่น้อยที่สุดที่จะเก็บได้
    
        unordered_map<int , int> find; //เป็น key , เลข
        for (int i = 0; i < inorder.size();i++){ 
          find[inorder[i]]++; //ก็คือเอาเลขนี้เป็น key [inorder[i]] เเล้วค่อยบวก
          maxs = max(find[inorder[i]] , maxs);
        }
        vector<int> answer; // สร้างไว้ return
        for (auto i  : find){ //auto ปรับ type ตามตัวนั้นๆ
            if (i.second == maxs){ //.first คือเอา key .second คือเอา value .first .sencond เอามาจาก
                                   //  unordered_map<int , int> find <int , เเรกคือ .first (key) , int> สองคือ .second (value)
              answer.push_back(i.first);
            }
        }
        return answer;
    }
};