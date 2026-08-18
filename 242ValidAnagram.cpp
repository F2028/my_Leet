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
using namespace std;    
class Solution {
public:
    bool isAnagram(string s, string t) {
        return sort(s.begin(),s.end()) , sort(t.begin(),t.end()) , s == t;
            // sort s(begin - end) , sort t(begin - end) then do s == t?
    }
};
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()){  // check edge case
            return false;
        }
        return sort(s.begin(),s.end()) , sort(t.begin(),t.end()) , s == t;
         
    }
};