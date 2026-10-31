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
#include <queue>
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) { //คือการ slide window เลื่อน 1 ลบอก 1
        int sum = 0;
        int newsum = 0;
        for (int i = 0; i < k;i++){
            sum += nums[i];
        }
        double max = sum;
        for (int i = k; i < nums.size();i++){
            newsum = sum - nums[i - k] + nums[i]; //อันนี้คือสูตร
            //ตัวบวกใหม่ = ตัวบวกเก่า - nums[i(indexปัจจุบัน) - k(ขอบเขตที่กำหนดมา)] + nums[i](ที่เป็นเลขปัจจุบัน)
            sum = newsum; //อย่าลืมให้ตัวเก่า = ตัวใหม่
            if (max < newsum){ //ถ้าเกิดค่ามากสุดอันเก่า < ตัวบวกใหม่
                max = newsum; // ให้ ค่ามากที่สุด = ตัวบวกใหม่
            }
        }
        return max / k;
    }
};