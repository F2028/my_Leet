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
using namespace std;    
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int , int > dupe;
        for (int i = 0; i < nums.size();i++){
            if (dupe.find(nums[i]) != dupe.end()){  // if found nums[i] in dupe , dupe.end() mean
                                                    // if [nums[i]] in dupe != dupe.end mean found nums[i] in dupe
                                                    //find(x) == end()  → ❌ ไม่มี x find(x) != end()  → ✅ มี x
                if((i - dupe[nums[i]]) <= k) return true;{ // current index - previouse index
             }
           }
                dupe[nums[i]] = i; // cuz we need to know index to calculate in else
                            // nums[3] = 1 [0,3] 3 place in index 1
        }
        return false;
    }
};