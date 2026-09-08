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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        for (int i = 0; i < nums1.size();i++){ //หา i วน size = nums1
            for (int j = 0; j < nums2.size();j++){ //หา j วน size = nums2
                bool found = false; //สร้างเพื่อไว้ตรวจว่าเจอตัวที่มากกว่าเเล้ว
                for (int k = j+1; k < nums2.size();k++){ // หา k วน size = nums2 เพื่อไว้หาตัวข้างหน้า
                    if (nums2[j] == nums1[i]){ // ถ้า j == i
                        if (nums1[i] < nums2[k]){ // เเละถ้า j == i เช็คว่า i น้อยกว่า k??
                            found = true; //เเสดงว่าเจอค่ามากกว่าเเล้ว
                            result.push_back(nums2[k]); //ดันเข้า
                            break; // break เพื่อไปทำรอบต่อไป
                        }
                     }
                 }
                 if (!found && nums1[i] == nums2[j]){ //ถ้าไม่เจอค่ามากกว่า เเละ i วนจนมาเจอ j อีกครั้ง (วน k หมดเเล้ว)
                    result.push_back(-1); // ดัน -1 เข้าไป
                    break; //break เพื่อนทำรอบต่อไป
                 }
            }
        }
        return result;
    }
};