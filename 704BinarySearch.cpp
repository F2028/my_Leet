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
public:
    int search(vector<int>& nums, int target) { //ตัดครี่งหา -> bainary search
        int L = 0;
        int R = nums.size() - 1; 
       while (L <= R){ //ถ้าซ้ายยังน้อยกว่าขวา
        int mid = L + (R - L) / 2; //กำหนดตัวกลางในการหา
        if (nums[mid] == target){
            return mid;
        }else if (nums[mid] < target){ //ถ้า สิ่งที่เรากำลังหาน้อยกว่า target ให้ตัดซ้ายทิ้งครึ่งหนึ่ง
            L = mid + 1;
        }else R = mid - 1; //เหมือนกันเเต่ตัดฝั่งขวาออก
       }
       return -1;
    }
};

class Solution { //ทำเเบบ recursion
public:
    int helper(vector<int>& nums , int target , int L , int R) {
            if (L > R) return -1; // base case every recursion dont need loops only base case
            int mid = L + (R - L) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) return helper(nums , target ,  mid + 1 , R);
            else return helper(nums, target , L , mid-1);
    }
    int search(vector<int>& nums, int target) {
       int L = 0;
       int R = nums.size() - 1;
       return helper(nums,target,L,R);
    }
};

class Solution { // STL bainary search
public:
    int search(vector<int>& nums, int target) {
        auto A = lower_bound(nums.begin() , nums.end() , target);
        // ให้ A = หาว่าตั้งเเต่ nums.begin(เริ่มต้น) จนถึง nums.end(จนจบ) หาค่า target
        // lower_bound return Lterator กลับมา เพราะงั้นถ้ามันชี้ example 9[index 5]
        // return A[5] - nums.begin[0] = int 5 not Lterator 5
        if (A != nums.end() && *A == target) return A - nums.begin(); //why A - nums.begin?
        else return - 1;
    }
};

class Solution { //vector find //ไม่นับใน solution นี้เเค่อยากให้เห็นว่า มันสามารถทำได้ใน solution คล้ายๆกัน
public: //solution นี้ต้องการ o long n find = o(n)
    int search(vector<int>& nums, int target) {
        auto A = find(nums.begin() , nums.end(), target);
        if (A != nums.end()) return A - nums.begin();
        else return -1;
    }
};