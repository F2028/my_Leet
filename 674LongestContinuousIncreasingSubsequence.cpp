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
#include <stack>
using namespace std;
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count = 1; //เริ่มจาก 1 เพราะ โจทบอกว่าต่อเนื่องกันอบ่างน้อย 1
        int maxcount = 1; //เริ่มจาก 1 เพราะ โจทบอกว่าต่อเนื่องกันอบ่างน้อย 1
        for (int i = 1; i < nums.size();i++){ 
          //เริ่ม 1 เพราะต้องการทุกลำดับเปรียบเทียบกันถ้าเริ่ม 0 nums[i-1] i = -1 error
          // ใช้ nums[i+1] เกินขอบเขตของ nums อีก
            if (nums[i] > nums[i-1]){
                count++;
                maxcount = max(maxcount , count);
            }else count = 1;
        }
        return maxcount;
    }
};