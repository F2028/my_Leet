#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;    
class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.size();
        int n = needle.size();
            for (int i = 0; i <= h - n; i++){          // if we make it haystack.size - needle.size it will underflow cuz 
                                                        //it not int it was unsigned if it negative number it will random number max = 18ล้านล้านล้าน
                bool found = true;                                              // make for only check true or not
                for (int j = 0 ; j < n; j++){                   //needle.size() cuz it will make loop check all needle if its haystack it will overflow
                    if (haystack[i+j] != needle[j]){                        // will break if letter not == [j]
                        found = false;                                         // check
                        break;
                      }
                    }
                    if (found){                                     // found == true  then return
                        return i;
                 }     
            }
            return -1;                                  //return -1 cuz if it return -1 it means all the loop already runs but cant found the equal
           
    }
};