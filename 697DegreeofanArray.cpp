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
#include <climits>
#include <queue>
#include <stack>
#include <numeric>
using namespace std;
class Solution {
public: //length = last[n] - first[n] + 1
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int , int> freq;
        unordered_map<int , int> firstI;
        unordered_map<int , int> lastI;
        int degree = 0;
        int length = 0; // ความยาวที่น้อยที่สุดที่เคยเจอ
        int subL = 0; //ความยาวของเเต่ละรอบ
        for (int i = 0; i < nums.size();i++){ //เพิ่ม ความถี่ index เเรก เเละ index ท้าย
            int x = nums[i];
            freq[x]++; //เพิ่มความถี่
            if (freq[x] == 1){
                firstI[x] = i; //update the first index we encounter
            }
            lastI[x] = i; //update the last position of last index
            degree = max(degree , freq[x]);
        }
        length = nums.size(); //เราทำเเบบนี้เพราะว่าต้องการให้มันเป็นเลขที่เยอะที่สุดก่อนเเล้วค่อยเปลี่ยนค่า
        for (auto [x , a] : freq){ //ทำเเบบนี้เพราะว่าเราต้องการเช็คค่าที่ไม่ซ้ำกัน
            //ถ้าทำ for (auto x : nums) มันจะเช็คทุกตัวของ nums มันจะover loop
            if (degree == a) { //ถ้าเกิดว่า 2 ตัวที่ซ้ำมีความถี่ที่ซ้ำกัน
                subL = lastI[x] - firstI[x] + 1;
                length = min(length , subL);
            }
        }
        return length;
    }
};