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
    string toLowerCase(string s) { // normal loop
        for (int i = 0; i < s.size();i++){
         s[i] = tolower(s[i]);
      }
      return s;
    }
};

class Solution { // range loop
public:
    string toLowerCase(string s) {
        for (char& x : s) x = tolower(x);  return s;
        //ใช้ & เพราะเราไม่ต้องการ x ที่เป็น copy ของ s เลยใช้ & เพื่อเอาค่า s ใส่ใน x เเต่ไม่ copy เปลี่ยน x = เปลี่ยน s
    }
};