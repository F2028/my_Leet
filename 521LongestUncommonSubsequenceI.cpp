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
    int findLUSlength(string a, string b) {
        if (a == b) return -1; // ถ้าคำมันเหมือนกัน return -1
        // ถ้าไม่ ทำ -->
        return max(a.length() , b.length());
    }
};