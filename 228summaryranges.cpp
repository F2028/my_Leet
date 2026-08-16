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
    vector<string> summaryRanges(vector<int>& nums) {
        int start = 0;
        vector<string> result;
            for(int i = 0; i <= nums.size() - 1;i++){
                if ( i == nums.size() - 1 || nums[i+1] - nums[i] != 1){ // check if it the last in vector , if it not continus
                      if (nums[start] == nums[i] ){ //check ตัวช่วงที่จบไปว่าเป็นต่อเนื่องตัวเดียวไหม ''
                            result.push_back(to_string(nums[start])); // push int that turned to string
                            start = i + 1;   // we need to update this if not it will stay at the same and cant be use to calculated
                      } else result.push_back(to_string(nums[start]) + "->" + to_string(nums[i])); 
                }
            }
            return result;
    }
};