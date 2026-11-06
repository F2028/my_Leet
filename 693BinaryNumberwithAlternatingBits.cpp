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
    string helper(int a){
        string bits;
        while (a > 0){
            bits += to_string(a % 2);//การmodulo A เพราะจะได้เเค่ 1 หรือ 0 เอาไว้เก็บbits พอดี
            a /= 2; // เอา A ไปหาร 2 ต่อ
        }
        reverse(bits.begin(),bits.end());
        return bits;
    }
    bool hasAlternatingBits(int n) {
        string A = helper(n);
        for (int i = 1; i < A.size();i++){
            if (A[i] == A[i-1]) return false;
        }
        return true;
    }
};