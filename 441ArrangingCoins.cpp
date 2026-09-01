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
    int arrangeCoins(int n) {
        long long k =(-1 + (sqrt(1 + n * 8))) / 2;
        return  k;
    }
};
// กัน edge case , overflow
class Solution {
public:
    int arrangeCoins(int n) {
        if (n == 0) return 0;
        long long k =(-1 + (sqrt(1 + 8LL * n))) / 2;
        return  k;
    }
};