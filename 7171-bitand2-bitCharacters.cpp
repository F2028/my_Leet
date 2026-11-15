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
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        while (i < bits.size() - 1){ // we use - 1 cuz เราไม่ต้องการให้มันรวมตัวสุดท้าย
            if (bits[i] == 0){
                i++;
            }else i += 2;
        }
        return i == bits.size() - 1; //เช็ค
    }
};