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
    int countSegments(string s) {
        string hee; // 
        stringstream word(s); // word got messsage [s]
        int count = 0; // starter
        while (word >> hee){ // if it can still printf word
           // เอาค่า wordมาเขียนใส่ hee
            count++;    //do this count++;
        }
        return count;
    }
};