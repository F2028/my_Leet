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
    int longestPalindrome(string s) {
        int count[52] = {};
        int result = 0;
        bool iseven = false;
        for (int i = 0; i < s.length();i++){
            if (islower(s[i])){ // หา index ให้ lover case
                count[s[i] - 'a' + 26]++;
            } else count[s[i] - 'A']++; // index upper case
        }
        for (int i = 0; i <= 51;i++){ // วนตาม index ทั้งหมด
            if (count[i] % 2 == 0) { // ถ้าเป็น odd 
                result += count[i]; // result += count[i] & ค่า i ใน count
            } else result += count[i] - 1 , iseven = true;
                // ถ้า even ให้ += เเล้ว - เปลี่ยนให้เป็น true เพื่อนจะเอาไปบวกทีหลัง
        }
        if (iseven){    // yes then do += 1
            result += 1;
        }
        return result;
    }
};