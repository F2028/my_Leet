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
class Solution { // helper
public:
    bool isprime(int n){
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n%2 == 0 or n % 3 == 0) return false;
        for (int i = 5 ; i * i <= n;i=i+6) if (n%i==0 or n%(i+2) == 0) return false;
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int tot, count = 0;
        for (int i = left ; i <= right;i++){
            tot = __builtin_popcount(i);
            if (isprime(tot)) count++;
        }
        return count;
    }
};