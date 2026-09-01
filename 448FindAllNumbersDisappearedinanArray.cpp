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
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int index = 0;
        vector<int> result;
        for(int i = 0; i < nums.size();i++){ // loop เอาตัวที่มีใน nums ติดลบ
            index = abs(nums[i]) - 1; //เลขที่เราเจอ มาหาตำแหน่งประจำของมัน
            if (nums[index] > 0){   //เอามาเพื่อนกันตัวที่มีค่าซ้ำ,mark ซ้ำ ถ้าค่าindex มากกว่า 0 ให้ติดลบ
                nums[index] = -nums[index];
            }       //ถ้าไม่ข้าม
        }
         for (int i = 0; i < nums.size();i++){ //loop หาตัวที่ไม่เคยมีใน nums
                if (nums[i] > 0){ //ถ้าไม่เคยโผล่เลยใน num
                    result.push_back(i+1); //ให้ทำ 
                }
            }
        return result;
    }
};