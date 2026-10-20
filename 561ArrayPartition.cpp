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
class Solution { // ใช้ sort
public:
    int arrayPairSum(vector<int>& nums) {
        vector<int> sorts = nums;
        int result = 0;
        sort(sorts.begin(),sorts.end());
        for (int i = 0;i < nums.size();i+=2){
            result += sorts[i];
        }
        return result;
    }
};

class Solution {
public:
    int arrayPairSum(vector<int>& nums) { // [1 , 4 , 3 , 2]
        map <int , int> keval; //already sort for us
        vector<int> order;
        int result = 0;
        for (int i = 0;i < nums.size();i++){
           keval[nums[i]]++; //add key[nums][1],[2],[4] add value [nunms[i]]++
        }
          for (auto p : keval ){ //หลังสร้าง key , valueเสร็จ
           for (int j = 0; j < p.second;j++){ //ใช้ sec เพราะถ้าจำนวนครั้งที่ออกมามากกว่า j ไม่ทำ
                                                            //(มากกว่าเพื่อน)
            order.push_back(p.first); //pushback key เข้าไป
                 }
            }
        for (int i = 0;i < nums.size();i+=2){ // หาค่า
            result += order[i];
        }
        return result;
    }
};