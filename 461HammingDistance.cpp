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
    int hammingDistance(int x, int y) {
        int count = 0;
        int n = x ^ y; //เอามา xor กัน 0 ^ 1 = 1 , 0 ^ 0 = 0 , 1 ^ 1 = 0
        while (n != 0){ // ถ้ายังไม่เป็น 0 ทำไปเรื่อยๆ
            count++; 
            n = n & (n - 1); // ตัดเลขหลังสุดออก
        }
        return count;
    }
};