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
    bool wordPattern(string pattern, string s) {
          unordered_map<string , char> sameword;
          unordered_map<char , string> samechar;
          stringstream words(s);
          string word;
          for (int i = 0;i < pattern.length();i++){
               if (!( words >> word)){  //check if words can print word 
                    return false;
               }
               if (samechar.find(pattern[i]) == samechar.end()){ // find char[i] in samechar
                    samechar[pattern[i]] = word;
               } else {
                    if (samechar[pattern[i]] != word){ // if char[i] != word 
                         return false;
                    }
               }
               if (sameword.find(word) == sameword.end()){ //find sameword(word) is in word??
                    sameword[word] = pattern[i];  //if yes do <-
               } else {
                    if (sameword[word] != pattern[i]){ //if samewword != char[i]
                         return false;
                    }
               }
          }
               if ((words >> word)){    //check again if s > pattern
                    return false;
               }
          return true;
    }
};