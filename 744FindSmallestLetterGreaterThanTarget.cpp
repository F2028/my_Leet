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
class Solution { // linear
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (int i = 0 ; i < letters.size();i++){
            if (letters[i] > target){
                return letters[i];
            }
        }
        return letters[0];
    }
};

class Solution { // bainary search
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2; 
            if (letters[mid] <= target){
                left = mid + 1;
            }else right = mid - 1;
        }
        return letters[left % letters.size()]; 
        //ใช้ left เพราะมันจะไปอยู่ที่ first greater พอดี ถ้าloopจบ
        //จะ return ตัวเเรกกรณีหาบ่เจอ
    }
};