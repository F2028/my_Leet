#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <set>
#include <cmath>
using namespace std;    
class Solution {
public:
    bool isHappy(int n) {
        int digit = 0;
        int sum = 0;
        set<int> seen;
        while (n != 0){
             sum = 0;
             if (seen.find(n) != seen.end()){
               return false;
             } else  seen.insert(n);
            while(n!= 0){
            digit = n % 10;
            sum += digit * digit;
            n = n / 10;
            }
             n = sum;
             if (n == 1){
                return true;
             }

        }
        return true;
    }
};