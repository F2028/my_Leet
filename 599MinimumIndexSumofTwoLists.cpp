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
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
      int sum = INT_MAX;
      vector<string> A;
      for (int i = 0; i < list1.size();i++){ // loop list1 member
        for (int j = 0; j < list2.size();j++){ // loop list2 member
          if (list1[i] == list2[j]){ //ถ้าเหมือน
             if (i + j < sum){ //ถ้าน้อยกว่า sum
              A.clear(); // clear ก่อนเผื่อเอา push_back ตอน == มา
            sum = i + j; // ให้ sum = i + j ถ้าน้อยกว่า sum
            A.push_back(list1[i]); //ดันเข้า A กรณี คำเหมือน เเละ index น้อยกว่าค่า index เดิม
           } else if (i + j == sum){ // ถ้าเท่า push_back list1 เข้า A
            A.push_back(list1[i]);
           }
          }
        }
      }
      return A; // return
    }
};