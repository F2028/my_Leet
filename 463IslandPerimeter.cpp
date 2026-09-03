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
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        vector<pair<int , int>>direction = { //สร้าง direction เพื่อวนหาทิศทาง
        {-1 , 0}, // direction ของ i & [row]
        {1 , 0},  // direction ของ i & [row]
        {0 , -1}, // direction ของ j & [column]
        {0 , 1}   // direction ของ j & [column]
        };
        for (int i = 0; i < grid.size();i++){ // row
          for (int j = 0; j < grid[0].size();j++){ // column & จำนวนเเถวช่องเเรก = 4 นับเเทนเป็น columnเเทนได้
            if (grid[i][j] == 1){
              for (int k = 0; k < direction.size();k++){
                int diri = direction[k].first; //เรียกใช้ first เพราะ direction มันเก็บเป้นคู่ [0 , 1] เลยเรียกใช้ได้
                
                int dirj = direction[k].second;//เรียกใช้ second เพราะ direction มันเก็บเป้นคู่ [0 , 1] เลยเรียกใช้ได้
                
                int ni = i + diri; // กำหนดค่า row + direction all 4 dir
               
                int nj = j + dirj; // กำหนดค่า column + direction all 4 dir
                 
                if (ni < 0 || ni >= grid.size() ||nj < 0 || nj >= grid[0].size() ){
                   
                  perimeter++; // ถ้า ni , njเกินขอบเขต grid ในโจทนี้=(น้อยกว่า 0 || มากกว่า 3) ของทั้ง row , column
                  
                } else if (grid[ni][nj] == 1){ //ถ้าช่องข้างๆเป็น land เหมือนกันจะไม่นับเป็นสุดขอบเกาะ
                 
                } else perimeter++; // ถ้าข้างๆเป็นน้ำนับเพราะคือสุดเกาะ
              }
            }
          }
        }
        return perimeter;
    }
};