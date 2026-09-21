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
    bool detectCapitalUse(string word) {
       int capital = 0;
       for (int i = 0; i < word.length();i++){
         if (isupper(word[i])) capital++;
       }
        if (capital == 0 || capital == word.length() || capital == 1 && isupper(word[0])) return true;
       return false;
    }
};
// ลองเเยก if ดีขึ้น 0.1 mb
class Solution {
public:
    bool detectCapitalUse(string word) {
       int capital = 0;
       for (int i = 0; i < word.length();i++){
         if (isupper(word[i])) capital++;
       }
       if (capital == 0) return true;
       if (capital == word.length())return true;
       if (capital == 1 && isupper(word[0])) return true;
       return false;
    }
};