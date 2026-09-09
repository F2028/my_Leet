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
    bool checkPerfectNumber(int num) {
        if (num == 1) return false;
      int result = 0;
      for (int i = 1; i <= sqrt(num);i++){ //ทำถึงเเค่ จุดตรงกลาง num
            if (num % i == 0){ // หาคู่ตัวเเรก
                result += i; // บวกได้เลย
            }
             if ( num % i == 0 and num / i != num and i != num / i){ //หาตัวสอง เผื่อมันบวกตัวซ้ำกัน
                result += (num / i); // อันนี้คือคู่ใหญ่
            }
       }
       return result == num;
    }
};