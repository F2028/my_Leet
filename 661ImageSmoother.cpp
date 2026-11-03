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
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int r = img.size(); // rows
        int c = img[0].size(); //this is collums
        vector<vector<int>> A(r , vector<int>(c , 0));
        // คือการสร้าง matrix เเยกที่ละส่วน vector<int>(c,0) คือมีจำนวน "c" เเละทุกตัวมีค่า "0"
        // r , vector<int>(c,0) สร้างจำนวนเเถว "r" 
        for (int i = 0; i < r;i++){ // rows ปัจจุบัน
            for (int j = 0; j < c;j++){ //collums ปัจจุบัน
                int sum = 0;
                int count = 0;
                for (int dr = -1; dr <= 1;dr++){ // ระยะการเลือนของเเนวตั้ง [rows]
                    for (int dc = -1; dc <= 1;dc++){ // ระยะการเลือนของเเนวนอน [collums]
                        int nr = i + dr; //rows ของตัวข้างๆ
                        int nc = j + dc; // collum ตัวข้างๆ
                        if (0 <= nr and nr < r and 0 <= nc and nc < c){
                        // ตรวจขอบเขต
                        // เช็คว่า nr จะต้องไม่ติดลบก็คือมากกว่า= 0 เเละ nr จะต้องไม่เกินจำนวนของ rows
                         // เช็คว่า nc จะต้องไม่ติดลบก็คือมากกว่า= 0 เเละ nc จะต้องไม่เกินจำนวนของ collums
                            sum += img[nr][nc]; 
                        // นำค่าของตำเเหน่งข้างๆ [rows][collum] ที่อยู่ในขอบเขตมาบวกสะสมใน sum 
                            count++;
                        }
                    }
                }
                A[i][j] = sum / count;
            }
        }
        return A;
    }
};