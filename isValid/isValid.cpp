#include <iostream>
#include <unordered_map>
#include <map>
#include <stack>  
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> spec;
            unordered_map<char , char> pair = {         
                    {')', '('},
                    {']', '['},
                    {'}', '{'}
            };
               for (char i : s){                            
                    if (i == '(' || i == '[' ||  i == '{'){
                        spec.push(i);
               } else {
                    if (spec.empty() || spec.top() != pair[i]){            
                            return false;
                    }
                    spec.pop();                                     
                
                }
            }
         return spec.empty();
        }                             
};
