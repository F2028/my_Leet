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
class Solution {  // bainary search
public:
    bool isPerfectSquare(int num) {
        if (num < 0) return false;
        if (num == 1) return true;
        int left = 1;
        int right = num / 2;
        while (left <= right){
             long long mid = (left + right) / 2;
            if (mid * mid < num){
               left = mid + 1;
            }
             else if (mid * mid > num){
               right = mid - 1;
            }
            else  return true;    
        }
        return false;
    }
};
// normal human begin
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0) return false;
        if (num == 1) return true;
        for (long long i = 0 ; i < num;i++){
            if (i * i == num){
                return true;
            }
        }
        return false;
    }
};