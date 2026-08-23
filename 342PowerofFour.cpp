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
    bool isPowerOfFour(int n) { //bits manipulate
        return n > 0 && ((n & (n - 1)) == 0 && ((n & 0xAAAAAAAA) == 0));
    }       
};
bool isPowerOfFour(int n) { // bits + math
        return n > 0 && ((n & (n - 1)) == 0 && (((n - 1) % 3) == 0));
    }
    