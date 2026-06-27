#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
            if (x < 0){
                return false;
            }
            long long a = 0;
            int b = x;
           while (x != 0){
              int digit = x % 10;       
               a = a * 10 + digit;      
              x = x / 10;
            }
            return {b == a};
    }
};