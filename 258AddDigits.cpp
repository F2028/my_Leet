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
using namespace std;    
class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return num;{}
        int sum = 0;
        int lastdigit = 0;
                  while (num != 0){ // เเยกให้ num = 1 + 2 + 3 + 4
                    lastdigit = num % 10;   // lastdigit
                    num = num / 10;     // ตัดตัวหลังออกเอาไปคำนวณได้
                    sum += lastdigit;
                  }
                   while(sum >= 10){  // if still > 10 do ->
                         lastdigit = sum % 10;
                         sum = sum / 10;
                        sum += lastdigit;
                    }
     
        return sum;
    }
};

// follow up 
class Solution {
public:
    int addDigits(int num) {    //used 9 เพราะมาันเป็นสูตรลัดใน math
        if (num == 0) return 0;{}
        if (num % 9 == 0) return 9;{}
         int result = num % 9;
         return result;
    }
};