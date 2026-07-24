#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
using namespace std; 
class Solution {
public:
    int climbStairs(int n) {        // dp = dynamic programming
        if (n == 1){
            return 1;
        }
      vector<int> ways(n+1);        //สร้าง variableให้ตรงกับ index
      ways[1] = 1;                  // เรารู้อยู่ละอันนี้ คือ step เเรก
      ways[2] = 2;                  // step 2
        for (int i = 3; i < ways.size();i++){       // ให้มันวนเท่า n && ways.size() = n+1   i < n+1 
            ways[i] = ways[i-1] + ways[i-2];        // ways[i] = ways[2-1] + ways[2-2] = ways[1]
        }
        return ways[n];             //
    }
};