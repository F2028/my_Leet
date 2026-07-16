#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {      
           int write = 0;                   // bugged cuz u make it 1 means u already have 2 unique value

           for (int i = 1; i < nums.size();i++){
                if (nums[i] != nums[write]){        // [2] != [1]   |   [4] = [2]
                    write++;                        // [2] , [1+1]  |   [4] = [2+1]
                    nums[write] = nums[i];          //  [2] = [2]   |   nums[3] <- nums[4]   == nums[4]
                }
                
           }
           return write + 1;            // cuz it need all value not index
    }
};