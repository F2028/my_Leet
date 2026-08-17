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
using namespace std;    
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n > 0 && (n& ( n-1)) == 0){ //หาว่า n > 0 เเละ n(bits) - n - 1 == 0000 bits??
                                        //เพราะ power2 จะมี 1 ตัวเดียวใน bits - (n-1) จะเท่ากับ 0  bits
            return true;
        }
        return false;
    }
};
//เเบบสั้นๆ
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0 && (n& ( n-1)) == 0);
    }
};
