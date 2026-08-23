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
    bool helper(char s){
         if (tolower(s) == 'a' || tolower(s) == 'e' 
            || tolower(s) == 'i' || tolower(s) == 'o'
            || tolower(s) == 'u'){
                return true;
            }
            return false;
    }

    string reverseVowels(string s) {
        int left = 0;
        int right = s.length() - 1;
        while (left < right){
        if (!helper(s[left])){
            left++;
        }
        if (!helper(s[right])){
            right--;
        }
        if (helper(s[left]) && helper(s[right])){
            swap(s[left] , s[right]);
            left++;
            right--;
        }
    }
        
        return s;
    }
};