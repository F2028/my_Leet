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
    bool containsDuplicate(vector<int>& nums) {
          unordered_set<int> dupe;
            for (int i = 0; i < nums.size();i++){
                if (dupe.find(nums[i]) == dupe.end()){
                    dupe.insert(nums[i]);
                } else return true;
            }
            return false;
    }
};