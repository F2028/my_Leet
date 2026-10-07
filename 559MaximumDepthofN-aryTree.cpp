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
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        int maxdept = 0;
        for (Node* temp: root->children){ //วนให้ครบลูกทุกตัว
            maxdept = max(maxdept, maxDepth(temp)); // หาตัวที่ลึกที่สุด (maxdept[ที่เป็นตัวเเปร] , function maxDepth(temp[ที่เอาไว้วนค่า]))
        }
        return maxdept + 1;
    }
};