#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
using namespace std; 
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int i = m - 1; //ตัวท้ายของ m 
            int j = n - 1;  //ตัวท้ายของ n
            int k = m + n - 1;  //ตัวท้ายของทั้งสอง vector รวมกัน
            while (i >= 0 || j >= 0){
                if (i < 0){
                    nums1[k] = nums2[j];        // keep in nums1[k] cuz we need to return nums1 and [k] mean all the val keep in k
                    j-- , k--;
                } else if (j < 0){
                    nums1[k] = nums1[i];        // --k all condition cuz it will keep k in present
                    i-- , k--;
               } else {
                if (nums1[i] > nums2[j]){
                    nums1[k] = nums1[i];
                    i-- , k --;
                } else {
                nums1[k] = nums2[j]; j--, k--;
                }
               }
        }
    }
};