#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;    
 class Solution {
public:
    int reverseBits(int n) {
        int right = n & 1;
        int result = 0;
        for(int i = 0; i < 32;i++){
             right = n & 1;
             result = (result << 1) | right;
            n = n >> 1;
        }
        return result;
    }
};