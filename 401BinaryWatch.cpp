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
    int helper(int bits){
        int count = 0;
        while (bits != 0){
        bits = bits & (bits - 1);
        count++;
        }
        return count;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        for (int i = 0; i < 12;i++){ //find hours
            for (int j = 0; j < 60;j++){
            if (helper(i) + helper(j) == turnedOn){ // find minutes
                stringstream time; //its a box full of message use .str() to use message inside
                 if (j < 10){ //if j < 10 -> ...: "05" , ... : "08"
                    time << i << ":" << "0" << j; //put this message in to our box
                    result.push_back(time.str()); //push time.str() [time message] to result
                 } else  time << i << ":" << j , result.push_back(time.str()); 
              }                                   //push time.str() [time message] to result
           }
        }
        return result; // return
    }
};