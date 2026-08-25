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
    bool canConstruct(string ransomNote, string magazine) {
        int count[26] = {};
        for (int i = 0; i < magazine.length();i++){ // บวกเข้าไปใน count 
            count[magazine[i] - 'a']++;     //ใช้ [magizine[i] - 'a'] ++
        }
        for (int i = 0; i < ransomNote.length();i++){
            count[ransomNote[i] - 'a']--;       //ลบcountจากค่าที่เเ้ล้วโดยใช้ตัวอักำศรใน ransomnote

            if (count[ransomNote[i] - 'a'] < 0) return false; //ถ้าติดลบเเสดงว่าไม่เท่า return false
            }
        return true;
    }
};