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
    bool canWinNim(int n) {
        return n % 4 != 0; // return maximum remove per player + 1
    }
};