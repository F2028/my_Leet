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
    string toHex(int num) {
        if (num == 0) return "0";
        unsigned int n = num;
        string result;
        int digit;
        while (n != 0){
            digit = n & 15; //find เลขทาน 10
            if (digit > 9){ // > 10 เปลี่ยนเป็นตัวอักษร
                digit -= 10;  // - 10 เพื่อหาหลักหน่วย
               digit += 'a';    //เเล้วเอาไปบวกกับ 'a';
               result.push_back(digit);
            } else {
                digit += '0';   //บวกเลข '0' เพื่อให้เป็ฯ char
            result.push_back(digit);
            }
            n = n >> 4;  //ขยับไป 4 bits หน้า
        }
        reverse(result.begin() , result.end()); //reverse
        return result;
    }
};