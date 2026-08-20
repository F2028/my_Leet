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
    void moveZeroes(vector<int>& nums) {
        int notzero = 0;
        for (int i = 0;i < nums.size();i++){ //ทำให้ตัวที่ไม่ใช่ 0 ไปอยู่หลังๆ
               if (nums[i] != 0){            //ทำให้ตัวที่ไม่ใช่ 0 ไปอยู่หลังๆ
                    nums[notzero] = nums[i]; // ย้ายที่ != 0 ไปข้างหน้าข้างหลังจะได้เหลือ 0
                    notzero++;
               }
        }
          for(int i = notzero; i < nums.size();i++){ // วน notzero ถึงตัวท้าย
               nums[i] = 0; // give nums value i = 0
          }
    }
};