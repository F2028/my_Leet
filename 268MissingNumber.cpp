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
    int missingNumber(vector<int>& nums) {
          sort(nums.begin() , nums.end()); // sort ก่อน
          for(int i = 0;i < nums.size();i++){
               if (nums[i] != i){  //หาว่า nums[i] == i ไหมคือค่าใน num ที่sortเเล้วตรงไหมถ้าไม่ return i
                    return i;      
               }
          }
          return nums.size();    //ถ้าไม่มีไรพลาด return ขนาด vector ไป
    }
};

// follow up
class Solution {
public:
    int missingNumber(vector<int>& nums) {
       set<int> range;
          for (int num : nums){
               range.insert(num);
          }
          for (int i = 0; i <= nums.size();i++){
               if (range.find(i) == range.end()){ // find == end mean ไม่เจอให้ทำ
                    return i;  // อันนี้
               }
          }
          return nums.size();
    }
};
