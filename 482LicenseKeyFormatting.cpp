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
    string licenseKeyFormatting(string s, int k) {
        string result; //ไว้ return result ทั้งหมด
        int countstr = 0; // นับจำนวนอักษรที่เหลืออยู่
        int count = 0; // นับจำนวนgroupของข้อความ ที่เดิน
        for (int i = s.length() - 1;i >= 0;i--){ //เอาไว้นับคำทั้งหมดใน s
             if (s[i] != '-'){
                countstr++;
            }
        }
        for (int i = s.length() - 1; i >= 0;i--){ //ไว้pushเข้า result
            if (s[i] != '-'){ //ถ้าไม่ใช่ '-'
                result.push_back(toupper(s[i])); // push
                count++; //เพิ่มเพือเอาไปใช้ if หน้า
                countstr--; //ลบจำนวนคำทั้งหมดที่เราหามา
            }
            if (count == k && countstr != 0){ // ไว้push '-' ตอนที่ count == k เเละ จำวนวนตัวอักษรยังเหลือ
                count = 0; //ปรับให้เป็น 0 เพราะจะได้เอาไปคำนวณรอบต่อไป
                result.push_back('-');
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};