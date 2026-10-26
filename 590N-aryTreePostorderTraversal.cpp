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
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    void  helper(Node* root , vector<int>& result){
        if (!root) return;
        for (auto A : root->children){
            helper(A , result);
        }
        result.push_back(root->val); //ใช้ได้เลยเพราะมันคือค่า Node ที่ถูกส่งมา ณ ปัจจุบัน
    }
    vector<int> postorder(Node* root) {
        vector<int> ans;
        helper(root,ans);
        return ans;
    }
};

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if (!root) return {};
        for (auto A : root->children){
            vector<int> b = postorder(A);
            ans.insert(ans.end(),b.begin(),b.end());
        }
        ans.push_back(root->val);
        return ans;
    }
};