#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std; 
class Solution {
public:
    bool isPalindrome(string s) {
        string result = "";
        for (int i = 0; i < s.length();i++){
            if (isalnum(s[i])){
                result.push_back(tolower(s[i]));
            }
        }
        int left = 0;
        int right = (int)result.length() - 1;
        while (left < right){
            if (result[left] != result[right]){
              return false;
            }
            left++;
            right--;
        }
        return true;
    }
};