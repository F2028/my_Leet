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
    bool issame(TreeNode*a , TreeNode*b){
        if (!a and !b) return true;
        if (!a or !b) return false;
        if (a->val == b->val and issame(a->left,b->left) and issame(a->right,b->right)){
            return true;
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if (issame(root,subRoot)) return true;
        if (isSubtree(root->left,subRoot) or isSubtree(root->right,subRoot)) return true;
        return false;
    }
};