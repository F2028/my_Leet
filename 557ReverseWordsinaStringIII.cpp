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
    string reverseWords(string s) {
        int last = 0;
        for(int i = 0; i < s.length();i++){
            if (s[i] == ' '){ //ถ้าเจอ space
                reverse(s.begin() + last, s.begin() + i); //reverse(begin + last) , begin + i
                        //เพราะว่าเราต้องการคำที่ก่อน spaceเช่น last = 0 i = 5 reverse(begin[0] + 0 , begin[0 + 5])
                last = i + 1;
            }
        }
        reverse(s.begin() + last, s.end()); //เอาไว้ reverse ตัวท้าย
        return s;
    }
};
// result.push_back(reverse(s[last] , s[i])); ใช้ไม่ได้เพราะ reverse return void pushback cant do void