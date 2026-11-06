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
            a /= 2; // เอา A ไปหาร 2 ต่อเพื่อเอาไปหา bits ต่อไป
        }
        reverse(bits.begin(),bits.end()); //reverse เพราะต้อนที่เราเอาเข้า bits เเรกมันจะกลับทางกัน
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

class Solution { //ใช้ bits เเบบทีละตัว
public:
    bool hasAlternatingBits(int n) {
        int prev = -1;
        while (n > 0){
            int a = n & 1;
            if (a == prev) return false;
            prev = a;
            n >>= 1;
        }
        return true;
    }
};
