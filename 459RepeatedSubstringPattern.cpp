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
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        string result;
        for (int i = 1; i < s.length();i++){
          bool good = true; // ตั้งไว้เพื่อนเช็คสถานะว่า มันตรงหรือไม่ตรง
          if (n % i == 0){  // เอาไว้หาตัว substring ถ้าลงตัวก็ทำ ถ้าไม่ return false
             result = s.substr(0 , i); //นี่หาตรงนี้
             for (int j = i; j < s.length();j+=i){ //loop ไว้เช็ค string ว่าเหมือนกันไหม
            if (result != s.substr(j , i)){ // ถ้าไม่เหมือน result != ตั่งเเต่ s[ j(เริ่มที่index??) - i(จำนวน)]
                good = false; // ตั้ง false ไว้ return ตอนจบ inner loop
                              //ต้องตั้งเเบบนี้เพราะว่าเราไม่ต้องการให้ค่ามันกลับไปเป็น true
                break; //เเล้วก็ทำให้ inner loop จบเลย
               }
             }
           } else good = false;
           if (good) return true; // ตัวตัดสิน
        }
        return false;
    }
};