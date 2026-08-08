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

//another solution
//another solution
class Solution {
public:
    int majorityElement(vector<int>& nums) {    // [2,2,1,1,1,2,2]
        unordered_map<int,int> count;
            for(int i = 0;i < nums.size();i++){ 
                count[nums[i]]++;               // count[nums[2]] ++ = count 2 = 1 ;count[nums[2]] ++ = 2 = 2 count[nums[1]]++ = count [1] = 1
                    if (count[nums[i]] > nums.size() /2 ){      // if (count[nums[2]] > nums.size() / 2 = 3)
                        return nums[i];                         // return nums[2] = 2
                    }
            }
            return 0;
    }
};