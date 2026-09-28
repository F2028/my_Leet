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
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size();i += 2 * k){ //ใช้ k * 2 เพราะว่าโจทต้องการ 2k = 2 * k
        reverse(s.begin() + i , s.begin() + min(i + k , (int)s.size()));// reverseตัวที่ เริ่ม + i , กับ ตัวเริ่ม + i + k
        }                                          //ต้องใช้ (int) เพราะ .size . length คืนเป็น data type size_t
        return s; //เเละ return
    }
};