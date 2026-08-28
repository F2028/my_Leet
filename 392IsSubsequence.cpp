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
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true; //check if s empty return true
        int i = 0; // wait for s
        for (int j = 0; j < t.length();j++){ //let j run through t
            if (s[i] == t[j]){  // if index i in s & s[i] == index j in t
                i++;            // & t[j] then do i++;
            }
        }
        return i == s.length(); //if i[number] == length of s[number]
    }
};