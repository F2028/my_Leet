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
    int findComplement(int num) {
       int mask = 0; //สร้างมาเพื่อตั้งให้เป็น bits ตามจำนวน bits ของ num
       int n = num;
       int count = 0;
       while (n > 0){ //การนับ bits โดยไม่สน 0 , 1
        count++;
        n = n >> 1; //shift ไป 1 ตัว , เลื่อนไป 1 bits
       }
       for (int i = 0; i < count;i++){ // วนตาม bits ที่ได้มาจาก count
        mask = (mask << 1) | 1; // 
       }
       return mask ^ num;
    }
};