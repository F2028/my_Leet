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
        for (int i = 0; i < nums.size();i++){
            if (nums[big] < nums[i]){
                big = i;
            }
        }
        for (int a : nums){
            if (a == nums[big]) continue;
            if (nums[big] < 2 * a) return -1;
        }
        return big;
    }
};