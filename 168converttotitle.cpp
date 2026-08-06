#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std; 
class Solution {
public:
    string convertToTitle(int columnNumber) {
            string ans;
            while(columnNumber != 0 ){
                        int temp = columnNumber - 1;
                        int index = temp % 26;          //หาตัวอักษร
                        columnNumber = temp / 26;       //เอาไปหาตัวถัดไป
                        ans.push_back('A' + index);     // ดันเข้า ans
            }
            reverse(ans.begin() , ans.end());           
            return ans;
    }
};