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
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        int digit = 0;

        for (int i = left ; i <= right;i++){ //วน loop ซ้าย ไป ขวา
            int temp = i; // กำหนดให้หาตัวนี้ก่อน
            bool real = true;
            while (temp > 0){ // เอามาใช้ใน while เพราะเราต้องหาทีละตัวใช้ while ง่ายกว่า 2 for loop
                digit = temp % 10; // ตัดให้เหลือเลขตัวเดียว
                if (digit == 0 or i % digit != 0){ //เเล้วถ้า digit == 0 หรือ i modulo digit != 0
                    real = false; // ให้ false เพราะ ถ้า digit == 0 หาต่อไม่ได้เป็น invalid
                    // i % digit != 0 เเสดงว่ามันหารตัวมันเองไม่ได้
                    break;
                }
                temp /= 10; //เเล้วก็ต้ดเลขสุดท้ายออก
            }
            if (real) ans.push_back(i);
        }
        return ans;
    }
};

class Solution { // Mathmethic + no use boolean + helper
public:
    bool helper(int num){ //ใช้เอาเเทนการใช้ boolean
            for (int p = 1 ; p <= num;p*=10){
                int digit = (num / p) % 10;
                if (digit == 0 or num % digit != 0){
                    return false;
                }
            }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right;i++){
            if (helper(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

class Solution {  // let fn reponsibility we do only return
public:
    vector<int> helper(int left , int right , vector<int>& A){ 
        int digit = 0;
        for (int i = left ; i <= right;i++){ 
            int temp = i; 
            bool real = true;
            while (temp > 0){ 
                digit = temp % 10; 
                if (digit == 0 or i % digit != 0){
                    real = false; 
                    break;
                }
                temp /= 10; 
            }
            if (real) A.push_back(i);
        }
        return A;
        
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        return helper(left , right , ans);
      
    }
};