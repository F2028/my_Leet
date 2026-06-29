#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
                map<char , int> Roman;
                Roman['I'] = 1;
                Roman['V'] = 5;
                Roman['X'] = 10;
                Roman['L'] = 50;
                Roman['C'] = 100;
                Roman['D'] = 500;
                Roman['M'] = 1000;

                    int total = 0;
                    for (int i = 0;i + 1 < s.size();i++){           // i + 1 for protected overflow but how??
                        if (Roman[s[i]] < Roman[s[i + 1]] ){
                          total = total - Roman[s[i]];        // total = total + cuz it gonna add to next loop
                        } 
                        else total = total + Roman[s[i]];     // if we use total = ... it gonna stay still not gonna increase more // 0 = 0 + [1]
                        
                    }   
                    total = total + Roman[s[s.size() - 1]];     // we need the last value of s[...]
                           return total;   // cuz it int function
    }                              
};