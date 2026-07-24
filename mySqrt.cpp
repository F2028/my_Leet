#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
using namespace std; 
class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        while (left <= right){
           long long mid = ((long long) left + right) / 2;      // ให้มันคำนวณได้หลายครั้ง    เปลี่ยนเป็น long long เพราะ overflow
            if (mid * mid < x){ 
                left = mid + 1;           //move pointer to right
            } else if (mid * mid > x){
                right = mid - 1;            //move pointer to left
            } else return mid;
            
        }
        return right;           // return right เพราะ ค่า - มันจะพอดี
    }
};