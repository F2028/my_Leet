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
    int thirdMax(vector<int>& nums) {
         set<int> dupe(nums.begin() , nums.end());
        if (dupe.size() >= 3){
            auto it = dupe.rbegin();    // rbegin ชี้ค่าที่มากที่สุดอยู่เเล้ว อันนี้คือกำลังชี้ตำเเหน่งอยู่
            it++; //+เพราะว่า ก็คือ rbegin = reverse begin เเต่เครื่องหมายไม่เปลี่ยนตาม
            it++;
            return *it; // * คือการชี้เอาค่าที่มันชี้อยู่มา
        }
        if (dupe.size() < 3){
            return *dupe.rbegin(); //เอาค่าท้ายของ rbegin เพราะมันชี้ตัวท้าย = เยอะสุด
        }
       
        return 1;
    }
};

//ของคนอื่น
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=nums.size()-1;i>=1;i--){
            if(nums[i]!=nums[i-1]){
                count++;
                if(count==2){
                    return nums[i-1];
                }
            }
        }
        return nums[nums.size()-1];
    }
};