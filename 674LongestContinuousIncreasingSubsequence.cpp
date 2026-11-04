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
using namespace std;
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) { //การนับเเละเก็บช่วงที่ดีที่สุด
        int count = 1; //เริ่มจาก 1 เพราะ โจทบอกว่าต่อเนื่องกันอบ่างน้อย 1
        int maxcount = 1; //เริ่มจาก 1 เพราะ โจทบอกว่าต่อเนื่องกันอบ่างน้อย 1
        for (int i = 1; i < nums.size();i++){ 
          //เริ่ม 1 เพราะต้องการทุกลำดับเปรียบเทียบกันถ้าเริ่ม 0 nums[i-1] i = -1 error
          // ใช้ nums[i+1] เกินขอบเขตของ nums อีก
            if (nums[i] > nums[i-1]){
                count++;
                maxcount = max(maxcount , count);
            }else count = 1;
        }
        return maxcount;
    }
};

class Solution { //ใช้ slide windows
                //ไม่ได้เห็นผลต่างมากเพราะ slide ไม่ได้เอามานับความยาวอย่างเดียวเอาไปทำอย่างอื่นได้อีก
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int start = 0; //จุดเริ่มต้นของ window
        int maxcount = 1;
        for (int i = 1; i < nums.size();i++){
            if (nums[i] > nums[i-1]){ //กรณีที่มันยัง increasing อยู่startจะยังไม่ขยาย
                                      //เเต่ window ยังขยายอยู่
                maxcount = max(maxcount , i - start + 1);
            } else start = i; //ถ้าไม่ window เก่าจะจบลง เเละ เริ่มwindow ใหม่ที่ start = i
            //window เก่าคือตั่งเเต่ start ถึง i ล่าสุดที่ยัง increasing อยู่ ถ้าไม่ increas ให้เอาอันเก่าทิ้งละเริ่มใหม่
        }
        return maxcount;
    }
};