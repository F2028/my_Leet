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
    vector<double> averageOfLevels(TreeNode* root) {
      vector<double> ans;
      if (!root) return {};
      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty()){
        double sum = 0;
        int size = q.size();
        for (int i = 0 ; i < size;i++){
            TreeNode* cur = q.front(); // q.front คือเอาตัวเเรกของ q มา cur = q(ตัวเเรก)
            q.pop();    //เอามาเเล้ว pop(เอาออก)
            if (cur->left){ //ถ้า cur(ซ้าย) -> true
                q.push(cur->left); //ให้ ดัน cur -> left เข้าไป q
            }
            if (cur->right){ //เหมือนกัน
                q.push(cur->right); //เหมือนกัน
            }
            sum += cur->val; //เอาผลรวมของ level มารวมกัน
        }
        ans.push_back(sum / size); // ดัน ค่าเฉลี่ยที่ (ผลรวมทั้งหมด(levelนันๆ) มาหาร size(q.size))
      }
      return ans;
    }
};