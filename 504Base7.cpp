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
    string convertToBase7(int num) {
        if (num == 0) return "0"; 
        bool negative = num < 0; // checkว่าถ้าค่าที่ได้มาตอนเเรกติดลบเราจะเอาไป += "-"
        string result; // ไว้ return
        int n = abs(num); //บังคับให้เป็นจำนวนเต็ม + ก่อนเพื่อจะได้เอาไปคำนวณถูก
        while (n > 0){
            result += to_string(n % 7); // n % 7 cuz base 7
            n /= 7; // same for this but this for the next round of loop
        }
        if (negative){ // ถ้าตอนเเรกมันเป็น - เราจะได้ยัด "-"เข้าไป
            result += "-";
        }
        reverse(result.begin(),result.end());
        return result;
    }
};