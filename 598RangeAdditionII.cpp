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
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if (ops.size() == 0) return m * n; // ถ้า operation ไม่มีให้คืน x * n // formula
        for (int i = 0; i < ops.size();i++){
          m = min(m , ops[i][0]);  //เราต้องเก็บเเถวที่เล็กที่สุด //เข้าถึง vector<vector>> เเบบนี้ [][]
          n = min(n , ops[i][1]);  //ความcolum
        }
        int total = m * n ; // return ค่าทั้งสองที่ * กัน
        return total;
    }
};