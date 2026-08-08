#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std; 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int points = 0;
        int candidate = 0;
            for (int i = 0; i < nums.size();i++){   
              if (points == 0){
                candidate = nums[i];
                points++;

              } else if (nums[i] == candidate){
                    points++;
                    
              } else points--;
            }
            return candidate;
    }
};