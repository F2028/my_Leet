#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <set>
#include <cmath>    
using namespace std;    
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char , char> seen;
        unordered_map<char , char> used;
        for(int i = 0; i < s.length();i++){
            if (seen.find(s[i]) == seen.end() && used.find(t[i]) == used.end()){
                seen[s[i]] = t[i];
                used[t[i]] = s[i];
            }
            if (seen[s[i]] != t[i])return false;{}
        }
        return true;
    }
};