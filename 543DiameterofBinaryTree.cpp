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
 class Solution { // 0(n**2)
public:
    int gethieght(TreeNode* root){ //เอาไว้หาความลึกที่เยอะที่สุด
        if (root == nullptr) return 0;
        return 1 + max(gethieght(root->left) , gethieght(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        int hleft = gethieght(root->left);  //ความสุงซ้าย
        int hright = gethieght(root->right); //ขวา
        int dleft = diameterOfBinaryTree(root->left); // หาเส้นทางที่ยาวที่สุดของซ้าย
        int dright = diameterOfBinaryTree(root->right); //ขวา
        return max({hleft + hright , dleft , dright});
    }
};
// อีก solution 0(n)
class Solution {
public:
    int maxdia = 0; //ตั้งไว้เพือหาค่า dia ที่เยอะที่สุดเอาไป compare
    int helper(TreeNode* root){
        if (!root) return 0;
        int hleft = helper(root->left);
        int hright = helper(root->right);
        if (hleft + hright > maxdia){ //ถ้า ความสูงซ้าย + ขวา > ค่า maxdia
            maxdia = hleft + hright;  // maxdia = (...)
        }
        return 1 + max(hleft,hright); //ถ้า maxdia มากสุดละ return กลับไป
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxdia = 0;
        helper(root);
        return maxdia;
    }
};