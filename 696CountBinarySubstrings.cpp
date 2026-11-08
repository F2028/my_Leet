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
#include <climits>
#include <queue>
#include <stack>
#include <numeric>
using namespace std;
class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0; //เอาไว้จัดกลุ่มของรอบที่เเล้ว
        int curr = 1; //จำนวนของกลุ่มตัวเลขปัจจุบัน
        int ans = 0; // เอาไว้คำนวณคำตอบ
        for (int i = 1; i < s.length();i++){ 
            if (s[i] == s[i-1]) { //ถ้าตัวเลขเหมือนกันจัดกลุ่มให้อยุ่กลุ่มเดียวกัน
                curr++; //จำนวนตัวเลขของกลุ่ม +1
            }else { //ถ้าตัวเลขไม่เหมือน 
                ans += min(curr,prev); //เอาจำนวน น้อยสุดของ (จำนวนตัวเลขกลุ่มปัจจุบัน , ตัวเลขของรอบก่อนหน้า)
                prev = curr; //เเล้วให้ ตัวก่อนหน้า = ตัวของปัจจุบัน
                curr = 1; // reset ให้เริ่ม 1 ใหม่
            }
        }
        ans += min(curr,prev); //เเล้ว + กันรอบท้ายเพราะ loop ไปไม่ถึงรอบสุดท้ายจริงๆ
        return ans;
    }
};

class Solution { // 2 pointer , group expan
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        int i = 0;
        while (i < s.size()){
           int j = i; // current groups
           while (j < s.size() and s[j] == s[i]){ // if j lower than s size and value
            // in s[j] and s[i] is the same
            j++; // we continue counting groups member
           }
           if (j == s.size()) break;
           int k = j;
           while (k < s.size() and s[k] == s[j]){ // same as above
            k++;
           }
           ans += min(j - i , k - j); // its just math 
           // basically its just do like 00 | 11 | 00 | 1  and we can get like 000 111 
           //Because we need equal numbers of zeros and ones in each substring.
           i = j; // move the start position to second group
        }
        return ans;
    }
};