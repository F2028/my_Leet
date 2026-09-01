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
    string addStrings(string num1, string num2) {
        int sum = 0;
        int carry = 0;
        string result;
        int lastnum1 = num1.length() - 1; // this is pointer
        int lastnum2 = num2.length() - 1; // this is pointer
        while (lastnum1 >= 0 || lastnum2 >= 0 || carry != 0){ //เอาเป็น condi เพราะว่าเราต้องเอามาลบอยู่เเล้ว
       int digit1 = 0; // ค่าของnum1 ที่ pointer มันชี้
       int digit2 = 0; // ค่าของnum2 ที่ pointer มันชี้
      if (lastnum1 >= 0)  digit1 = num1[lastnum1] - '0'; // ตรงนี้กำนหนดค่า - '0' เพราะมันเป็น string ต้องลบเเบบนี้เราจะได้ค่ามา
      if (lastnum2 >= 0)  digit2 = num2[lastnum2] - '0'; // ตรงนี้กำนหนดค่า - '0' เพราะมันเป็น string ต้องลบเเบบนี้เราจะได้ค่ามา
            sum = digit1 + digit2 + carry; //เอามาบวกกันกับ [carry ในรอบหน้า]
            carry = sum / 10; // หา carry โดนหาร 10 ถ้ามากกว่า 10 = 1 
            result.push_back(sum % 10 + '0'); //ดันเข้าเพื่อเอาไปเก็บค่า + '0' เหมือน line 24
             lastnum1--; //ลบเพราะจะขยับ pointer
             lastnum2--; //ลบเพราะจะขยับ pointer
        }
        reverse(result.begin(),result.end()); // reverse เพราะตอนนี้ค่ามันกลับด้าน
        return result;
    }
};