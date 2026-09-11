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
    int fib(int n) {
        if (n <= 1){ // ถ้าน้อยกว่าเท่ากับ return ไป
        return n;
        }
      return fib(n - 1) + fib (n - 2); //เรียก recursion เเละ return
    }
};