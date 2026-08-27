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
    int firstUniqChar(string s) {
        int count[26] = {};
       for (int i = 0; i < s.length();i++){ //นับทุกตัว
        count[s[i] - 'a']++;
       }
       for (int i = 0; i < s.length();i++){ //เอาไปลบ char a เเล้วหาตำเเหน่ง
         if (count[s[i] - 'a'] == 1) return i; //return ตำเเหน่งที่ i
       }
       return -1; // not found return ...
    }
};