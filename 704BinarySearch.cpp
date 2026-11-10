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
#include <numeric>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) { //ตัดครี่งหา
        int L = 0;
        int R = nums.size() - 1; 
       while (L <= R){ //ถ้าซ้ายยังน้อยกว่าขวา
        int mid = L + (R - L) / 2; //กำหนดตัวกลางในการหา
        if (nums[mid] == target){
            return mid;
        }else if (nums[mid] < target){ //ถ้า สิ่งที่เรากำลังหาน้อยกว่า target ให้ตัดซ้ายทิ้งครึ่งหนึ่ง
            L = mid + 1;
        }else R = mid - 1; //เหมือนกันเเต่ตัดฝั่งขวาออก
       }
       return -1;
    }
};