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
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> a(n+1,0);
        // + 1 เพราะ top มันคือ cost.size() หรือ index = cost.size + 1
        a[0] = 0; //step 0 free
        a[1] = 0; //step 1 free
        for (int i = 2 ; i < a.size();i++){
            a[i] = min(a[i-1] + cost[i - 1] , a[i - 2] + cost[i - 2]);
            // คำนวณสูตร
        }
        return a[n]; //return a index n เพราะ top เรามี minimun ที่เราคำนวณไว้
    }
};

class Solution { // prev 1 + prev2 , Rolling DP / Space Optimization
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // + 1 เพราะ top มันคือ cost.size() หรือ index = cost.size + 1
        int prev1 = 0;  int prev2 = 0;
        for (int i = 2 ; i <= n;i++){
            int b = min(prev1 + cost[i - 1] , prev2 + cost[i - 2]);
             prev2 = prev1;
             prev1 = b;
            // คำนวณสูตร
        }
        return prev1; 
    }
};