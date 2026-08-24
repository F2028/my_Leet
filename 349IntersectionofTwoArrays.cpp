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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        set<int> num1;
        set<int> num2;
        for (int num : nums1){
            num1.insert(num);
        }
            for (int num : nums2){
                if (num1.find(num) != num1.end()){
                   if (num2.find(num) == num2.end()){
                    result.push_back(num);
                    num2.insert(num);
                   }
                }
            }
        
        return result;
    }
};