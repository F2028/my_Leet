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
class Solution { // depth first search , DFS = recursion
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

class Solution { //BFS  = avoid recursion
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;
        vector<pair<int,int>> udlr = {{1,0} , {-1,0} , {0,1} , {0,-1}};
        //เอ่ไว้หา 4 ทาง บน ,ล่าง , ขวา , ซ้าย
        queue<pair<int,int>> q;
        int oldcolor = image[sr][sc]; // กำหนดสีเก่าก่อน pop
        q.push({sr,sc});
        image[sr][sc] = color; // กำหนดให้จุดนี้เปลี่ยน เป็นอีกสีที่ต้องการ
        while(!q.empty()){
            pair<int,int> A = q.front(); //เพื่อ? //กำหนดตัวเเรกให้มัน
            int a = A.first , b = A.second; //เพิ่อ? // A.first = row , A.second = collums
            q.pop(); //ลบตัวหน้าสุดออก ทำงาน LIFO
            for (pair<int,int>& x : udlr){ // เดินทั้ง 4 ทาง
                int dr = a + x.first;
                int dc = b + x.second;
                if (dr >= 0 and dr < image.size() and dc >= 0 and dc < image[0].size()
                and image[dr][dc] == oldcolor) {
                // เช็คว่าเกินขอบเขตไหมทั้ง 4 ทาง เเละ ถ้าเป็นสีเดิมอยู่
                image[dr][dc] = color; //เปลี่ยน
                q.push({dr,dc}); //เเละดัน //เพิ้อ?
                }
            }
        }
        return image;
    }
};