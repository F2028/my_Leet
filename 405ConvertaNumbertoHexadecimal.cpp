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
    string toHex(int num) {
        if (num == 0) return "0";
        unsigned int n = num;
        string result;
        int digit;
        while (n != 0){
            digit = n & 15;
            if (digit > 9){
                digit -= 10;
               digit += 'a';
               result.push_back(digit);
            } else {
                digit += '0';
            result.push_back(digit);
            }
            n = n >> 4;
        }
        reverse(result.begin() , result.end());
        return result;
    }
};