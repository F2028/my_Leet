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
using namespace std;    
class Solution {
public:
    bool isUgly(int n) {
        if (n < 0)return false;
        if (n == 0)return false;
        if (n == 1)return true; //cuz 1 has no prime factor
        while(n != 0){
           if (n % 2 == 0){ // เช็คว่าหาร 2 ลงตัวไหม ถ้าใช้ do->
                n = n / 2;
           } 
           if (n % 3 == 0){ //เช็คว่าหาร 3 ลงตัวไหม ถ้าใช้ do->
                n = n / 3;
           }
           if (n % 5 == 0){ //เช็คว่าหาร 5 ลงตัวไหม ถ้าใช้ do->
                n = n / 5;
           }
             if (n % 2 != 0 && n % 3 != 0 && n % 5 != 0){ // return ถ้าหารอะไรไม่ลงตัวเลย
                 return (n == 1); // give bool back
                 // abother one like this
//  if (n % 2 != 0 && n % 3 != 0 && n % 5 != 0){
//    if (n == 1) {
//     return true;
//     } else {
//      return false;
//     }
// }

             }
        }
        return  true;
    }
};