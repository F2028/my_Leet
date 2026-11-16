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
    int pivotIndex(vector<int>& nums) {
        int left = 0;
        int total = accumulate(nums.begin() , nums.end() , 0); // accumulate(begin , end , started value)
        for (int i = 0; i < nums.size();i++){
            if (left == total - left - nums[i]) return i;
            left += nums[i];
        }
        return -1;
    }
};

class Solution { // use loop instead of accumulate
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0;
        int total = 0;
        for (int x :nums){
            total += x;
        }
        for (int i = 0; i < nums.size();i++){
            if (left == total - left - nums[i]) return i;
            left += nums[i];
        }
        return -1;
    }
};  

class Solution { // prefix sum + suffix sum
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n , 0); //ขนาด size = n เริ่มที่ 0 ทุกตัว
        vector<int> right(n , 0);
        for (int i = 1; i < nums.size();i++){
            left[i] = left[i-1] + nums[i - 1];
        }
        for (int i = n - 2; i >= 0;i--){
            right[i] = right[i+1] + nums[i + 1];
        }
        for (int i = 0; i < nums.size();i++){
            if (left[i] == right[i]) return i;
        }
        return -1;
    }
};