#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std; 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i : nums){
            result ^= i;       // ^ bitswise operater 
        }
        return result;
    }
};