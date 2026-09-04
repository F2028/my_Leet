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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0; // นับจำนวนที่เราได้ 1
        int maxcount = 0; //จำวนวนที่มากที่สุด count ทำได้
        for (int i = 0;i < nums.size();i++){ //loop หา count ที่ได้ 1 ทั้งหมด
            if (nums[i] == 1){ //ถ้าใช่
                count++;       // ทำอันนี้
            } else count = 0; // ถ้าไม่ให้ count = 0
            if (count >= maxcount){ // ถ้า count มากกว่า maxcount ปัจจุบันให้ maxcount = count ไปเลย
                maxcount = count;
            }
        }
        return maxcount;
    }
};