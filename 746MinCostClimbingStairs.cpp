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

class Solution { // recursion
public:
    int helper(int n , vector<int>& cost , vector<int>& dp){
        if (n == 0 or n == 1) return 0;
        if (dp[n] != -1) return dp[n];
        int one = helper(n-1 , cost , dp) + cost[n-1]; // recursion current position
        int two = helper(n-2 , cost , dp) + cost[n-2];
        dp[n] = min(one , two); // calculate the smallest steps
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
    int a = cost.size();
    vector<int> A(a+1,-1); // -1 cuz if its 0 its mean it is calculated
    return helper(a , cost , A); // เพราะ top เรามี minimun ที่เราคำนวณไว้
    }
};