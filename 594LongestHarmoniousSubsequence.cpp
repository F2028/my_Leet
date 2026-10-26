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
using namespace std;
class Solution {
public:
    int findLHS(vector<int>& nums) {
       unordered_map<int , int> find;
      for (int i = 0; i < nums.size();i++){ // assign ค่า find
        find[nums[i]]++;
      }
      int longest = 0;
      for (auto a : find){ 
        if (find.count(a.first+1)){
            longest = max(a.second + find[a.first+1] , longest);
            //ใช้ find[a.first+1] เพื่อค้นหา key หรือเอา key ปัจจุบันมาบวก 1
        }
      }
      return longest;
    }
};