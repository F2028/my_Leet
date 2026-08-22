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
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i = 0; i <= n;i++){ 
             int temp = i; //สร้างตัวชั่วคราวเพื่อรักษาลำดับของ i
             int count = 0; //ไว้สร้างตัวนับ 1
            while( temp != 0){
               count++;
               temp = temp & (temp - 1); // ลบตัวท้ายออก
            }
             ans.push_back(count);
        }
        return ans;
    }
};