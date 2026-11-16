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
    void helper(vector<vector<int>>& image ,int sr , int sc , int original , int color){
        
        if (sr < 0 or sr >= image.size() || sc < 0 or sc >= image[0].size()) return;
        //เช็คก่อนว่ายังยุในขอบเขต?
        if (image[sr][sc] != original) return; // ถ้าช่องที่เช็คอยู่ไม่ใช่สีจาก original ให้ return ออก
        image[sr][sc] = color; //เปลี่ยนให้เป็นสีอื่น , เปลี่ยนเลข
        helper(image , sr + 1 , sc , original , color); //ขึ้น
        helper(image , sr - 1 , sc , original , color); //ลง
        helper(image , sr , sc + 1 , original , color); //ขวา
        helper(image , sr , sc  - 1, original , color); //ซ้าย
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original = image[sr][sc];
        if (original == color) return; // ถ้าสีเดียวกันตั่งเเต่เริ่มให้ return อก
        helper(image , sr , sc , original , color);
        return image;
    }
};