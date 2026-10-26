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
    void helper(Node* root , vector<int>& num){ //ที่ทำเเบบนี้เพราะว่า Node* มันจะรับมาเเค่ทีละตัว
        // เเต่ root มีค่าเป็น vector เพราะงั้นจะส่ง root-> child ไม่ได้ เพราะ child มันเป็นเเบบ vector
        // [0 , 1 , 2 , 3] Node* มันจะรับเเค่อันเดียว
        if (!root) return; //ถ้า null return
          num.push_back(root->val); //เก็บค่าปัจจุบันก่อนเเล้วค่อยเดิน
        for (Node* child : root->children){ //เดินตรงนี้
            helper(child,num); // เรียก recursion
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> ans;
        helper(root,ans);
        return ans;
    }
};

class Solution { //อีก solution เเบบ no helper
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if (!root) return {};
        ans.push_back(root->val);
        for (auto child : root->children){
            vector<int> A = preorder(child); //ก็คือให้ A เก็บค่า recursion(child)ไว้
            ans.insert(ans.end(),A.begin(), A.end()); //ให้เริ่มใส่ที่ ans(ท้าย)ด้วยตัว A(ตัวเเรก) จนถึง A(ตัวท้าย)
        }
        return ans;
    }
};