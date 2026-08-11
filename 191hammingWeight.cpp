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
    int hammingWeight(int n) {
        int count = 0;
       while(n != 0){
            if ((n&1) == 1)count++;{}
            n = n >> 1;
        }
        return count;
    }
};