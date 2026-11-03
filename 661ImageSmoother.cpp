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
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) { //การnested 4 loops
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

class Solution {  //2D Prefix Sum
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int r = img.size();
        int c = img[0].size();
        vector<vector<int>> prefix(r+1,vector<int>(c+1,0));
        // prefix sum matrix
        //เรากำลังเพิ่มแถวและคอลัมน์เพียงแต่เพิ่มเฉพาะใน Prefix Matrix เพื่อทำให้สูตรคำนวณง่ายขึ้น
        vector<vector<int>> ans(r,vector<int>(c,0));
        for (int i = 1; i <= r;i++){
            for (int j = 1; j <= c;j++){
            // i , j จะเริ่มที่ 0 ไม่ได้เพราะมันจะเป็น img[i-1][j-1] = img[-1][-1] อยู่นอก matrix
                prefix[i][j] = img[i - 1][j-1]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
         // prefix ใช้ Index เริ่มต้นที่ 1
         // ส่วน img ใช้ Index เริ่มต้นที่ 0
         // จึงต้องใช้ img[i-1][j-1] เพื่อเชื่อมตำแหน่งของทั้งสอง Matrix
            }
        }
        for (int i = 0; i < r;i++){
            for (int j = 0; j < c;j++){
                int sum = 0;
                int count = 0;
                int r1 = max(0,i-1);// หา row เริ่่มต้นเเละจะต้องไม่ติดลบ
                int r2 = min(r,i+2);// หา row endเเละต้องไม่เกินจำนวน row
                int c1 = max(0,j-1);// หา collum เริ่่มต้นเเละจะต้องไม่ติดลบ
                int c2 = min(c,j+2);// หา collum endเเละต้องไม่เกินจำนวน collum
                // start = max ( 0, i - d[จำนวนตามช่อง flitterของโจท])
                // end = min (r , i + d + 1)
                // r1 = Row เริ่มต้น
                // r2 = Row สิ้นสุด (ไม่รวมตำแหน่ง r2)
                // c1 = Column เริ่มต้น
                // c2 = Column สิ้นสุด (ไม่รวมตำแหน่ง c2)
                sum = prefix[r2][c2]-prefix[r1][c2]-prefix[r2][c1] + prefix[r1][c1];
                //สูตรหาผลบวก
                count = (r2-r1) * (c2-c1);
                //สูตรหาจำนวนช่องทั้งหมด
                ans[i][j] = sum / count;
            }
        }
        return ans;
    }
};