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
using namespace std;
class Solution { // ทำเเบบ 2 pointer ได้
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
      int plnated = 0;
      for (int i = 0; i < flowerbed.size();i++){
        if (i == 0 or flowerbed[i - 1 ] == 0){ //เช็คฝั่งซ้ายว่าเป็น 0 ไหม
          if (flowerbed[i] == 0){ //ถ้าเป็น 0[ปลูกได้]
            if (i == flowerbed.size() - 1 || flowerbed[i + 1 ] == 0){ //เช็คขวาต่อว่าเป็น 0 ไหม
                flowerbed[i] = 1; //ถ้าผ่านให้ทำ สัญลักว่าเราเคยปลูกเเล้วเพื่อบอกรอบต่อไป
                plnated++; // ปลูก
              
            }
          }
        }
      }
        return plnated >= n;
    }
};