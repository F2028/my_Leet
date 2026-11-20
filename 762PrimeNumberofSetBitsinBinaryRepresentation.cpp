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
class Solution { // helper
public:
    bool isprime(int n){
        if (n <= 1) return false; // 1ไม่ใช่ prime 
        if (n <= 3) return true; // 2 , 3 ใช่
        if (n%2 == 0 or n % 3 == 0) return false; 
        // ถ้าหารด้วย 2 หรือ 3 ลงตัว ไม่ใช่ prime (ตัดไปครึ่งหนึ่ง ของเลขทั้งหมด)
        for (int i = 5 ; i * i <= n;i=i+6) if (n%i==0 or n%(i+2) == 0) return false;
        // ที่เหลือ เลข prime ทุกตัวที่ > 3 
        //อยู่ในรูป 6+-1 เลยลองหารแค่ i กับ i+2 โดย i เริ่มที่ 5 แล้วกระโดดทีละ 6
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int tot, count = 0;
        for (int i = left ; i <= right;i++){
            tot = __builtin_popcount(i); // คือฟังก์ชันสำเร็จรูปของ GCC/Clang 
            //ที่นับจำนวนบิต 1 ในเลขฐานสองของ x (ชื่อ popcount มาจาก “population count”)
            if (isprime(tot)) count++;
        }
        return count;
    }
};


class Solution { // helper
public:
    int helper(int n){
        int a = 0;
        while (n){
            n &= (n-1);
            a++;
        }
        return a;
    }
    int countPrimeSetBits(int left, int right) {
        int mask = 0;
        int count = 0;
       mask |= (1 << 2);
       mask |= (1 << 3);
       mask |= (1 << 5);
       mask |= (1 << 7);
       mask |= (1 << 11);
       mask |= (1 << 13);
       mask |= (1 << 17);
       mask |= (1 << 19);
        for (int i = left ; i <= right;i++){
            if ((1 << helper(i) & mask) != 0){
                count++;
            }
        }
        return count;
    }
};