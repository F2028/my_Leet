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
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return (bool)0;
        for (int i = 0; i < s.size();i++){
            char first = s[0];
            if (s == goal) return true;
            for (int j = 0; j < s.size()-1;j++){
                s[j] = s[j+1];
            }
            s[s.size()-1] = first;
        }
        return false;
    }
};