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
    char findTheDifference(string s, string t) {
        int count[26] = {};
        for (int i = 0; i < t.length();i++){
            count[t[i] - 'a']++;
        }
        for (int i = 0; i < s.length();i++){
            count[s[i] - 'a']--;
        }
        for (int i = 0; i <= 25;i++){
            if (count[i] == 1) return i + 'a';
        }
        return 'a';
    }
};