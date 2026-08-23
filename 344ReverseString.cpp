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
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};
// two pointer
 void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right){
            swap(s[left] , s[right]); // swap
            left++;
            right--;
        }
    }
