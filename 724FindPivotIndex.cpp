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
        int total = accumulate(nums.begin() , nums.end() , 0);
        for (int i = 0; i < nums.size();i++){
            if (left == total - left - nums[i]) return i;
            left += nums[i];
        }
        return -1;
    }
};