#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;    
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
            for (int i = digits.size() - 1; i >= 0;i--){
                    if (digits[i] < 9){         // is it real that it will plus the last index -> yes cuz it started right
                        digits[i]++;            // [1,2,3]  [i] = 2   i = 3++ =  4 [1,2,4]
                        return digits;
                    }
                    digits[i] = 0;            // it make 1,9,9 -> 2,0,0 if not it will be 2,9,9
            }
                    vector<int> nine(digits.size() + 1);
                    nine[0] = 1;
                    return nine;
     }
};