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
    int dominantIndex(vector<int>& nums) {
        int big = 0;
        for (int i = 0; i < nums.size();i++){ // หาค่ามากสุด
            if (nums[big] < nums[i]){
                big = i;
            }
        }
        for (int a : nums){ // วนหาตัว * 2 
            if (a == nums[big]) continue; //ถ้าเจอตัวเอง ให้ไปต่อเพราะไม่ต้องเอามาเทียบ
            if (nums[big] < 2 * a) return -1; // ถ้าเจอมากกว่า a * 2 > ตัวที่ใหญ่สุด
        }
        return big;
    }
};

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
    int index = 0;
    for (int i = 0; i < nums.size();i++){ 
            if (nums[index] < nums[i]){
                index = i;
            }
        }
        sort(nums.begin() , nums.end());
        return nums[nums.size() - 2] * 2 > nums[nums.size() - 1] ? -1 : index; 
    }
};