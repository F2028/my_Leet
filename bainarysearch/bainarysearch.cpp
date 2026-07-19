#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;    
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;     
        while(left <= right){           // if left > right exit loops
            int mid = left + (right - left) / 2;
            if (nums[mid] < target){            //อยู่ซ้าย mid ให้ right+
               left = mid + 1;

            } else if (nums[mid] > target){     //อยู่ขวา mid ให้ right -
                right = mid - 1;

            } else return mid;
        }
         return left;           // left มันจะขยับไปหาที่ๆ target ควรอยู่ ถ้าไม่เจอ
    }
};