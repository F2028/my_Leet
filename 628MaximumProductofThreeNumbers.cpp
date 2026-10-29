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
#include <climits>
using namespace std;
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
       vector<int> A = nums;
       int a = 0;
       int b = 0;
       sort(A.begin(),A.end());
        a = A[A.size()-1] * A[A.size()-2] * A[A.size()-3];
       if (A[0] * A[1] > 0){
        b = A[0] * A[1] * A[A.size()-1];
        if (b > a) {
          return b;
        }
       }
        
       return a;
    }
};

class Solution { //ใช้ formula
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        for (int i = 0; i < nums.size();i++){
          if (nums[i] > max1){ // ถ้ามันมากกว่าเลขที่มากที่สุด 3 ตัว
            max3 = max2; //ให้ตัวสุดท้าย = ต้ว 2
            max2 = max1; // ตัว2 = ตัวเเรก
            max1 = nums[i]; //ตัวเเรก = ตัวที่มากที่สุดที่เจอ
          } else if (nums[i] > max2 and nums[i] <= max1){ // ถ้าล่าสุดมากกว่า 2 เเต่น้อยกว่า 1
            max3 = max2; // 3 = 2
            max2 = nums[i]; // 2 = ตัวล่าสุด
          } else if (nums[i] > max3 and nums[i] <= max2) { // ถ้าล่าสุดมากกว่า 3 เเต่น้อยกว่า 2
            max3 = nums[i]; // 3 = ตัวล่าสุด
          } 
          if (nums[i] < min1){ // เอาไว้หาค่าน้อยที่สุด 2
            min2 = min1;
            min1 = nums[i];
          } else if (nums[i] < min2 and nums[i] >= min1 ){
            min2 = nums[i];
          }
        }
        // ทำทั้งหมดไปเพื่อหาตัวที่เยอะที่สุด 3 ตัว * กัน >? ค่าน้อยสุด 2 ตัว * ค่ามากที่สุด 1 
        //หาค่าน้อยกรณีที่มัน - , - * = + , + * ตัวล่าสุด
        return max(max1 * max2 * max3 , min1 * min2 * max1);
    }
};