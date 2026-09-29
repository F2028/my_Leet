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
class Solution {
public:
    bool checkRecord(string s) {
        int A = 0;
        int contiL = 0;
        for (int i = 0; i < s.size();i++){
            if (s[i] == 'A') A++;
            if (s[i] == 'L'){
                contiL++;
            } else contiL = 0;
            if (A >= 2 || contiL >= 3) return false;
        }
        return true;
    }
};