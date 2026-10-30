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
        double aver = 0;
        double sum = 0;
        int size = q.size();
        for (int i = 0; i < size;i++){
            TreeNode* cur = q.front();
            q.pop();
            if (cur->left){
                q.push(cur->left);
            }
            if (cur->right){
                q.push(cur->right);
            }
            sum += cur->val;
        }
        ans.push_back(aver = sum / size);
       }
       return ans;
    }
};