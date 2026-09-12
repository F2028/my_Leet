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
    vector<string> findWords(vector<string>& words) {
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";
        int row;
        vector<string> result; //เก็บเเต่ละคำ 
        for (int i = 0; i < words.size();i++){ //วนคำ
                  bool isfound = true;
          for (int j = 0; j < words[i].size();j++){ // วนตัวอักศรของคำ
           char word = tolower(words[i][j]);
           if (j == 0){ //ตั้งตัวเเรกกำหนด row ให้มันว่าเราจะไปทำ row ไหน
             if (find(row1.begin(), row1.end() , word) != row1.end()){ //ทำเพื่อกำหนดว่าเราจะเช็ค row ที่เท่าไหร่
                     row = 1;
            }else if (find(row2.begin(), row2.end() , word) != row2.end()){ //ทำเพื่อกำหนดว่าเราจะเช็ค row ที่เท่าไหร่
                     row = 2;
            }else if (find(row3.begin(), row3.end() , word) != row3.end()){ //ทำเพื่อกำหนดว่าเราจะเช็ค row ที่เท่าไหร่
                     row = 3;
             } 
            }
              if (j > 0){ //อักษรตัวต่อไปของคำ words[i]
            if (row == 1){ //จากด้านบน ถ้าได้ row ตามนี้ให้ทำข้างล่าง
                if (isfound and find(row1.begin(), row1.end() , word) != row1.end()){ //ถ้าตัวอักษรยังอยู่ใน row อยู่เเละ ยังเจออยู่
                  isfound = true;
                } else isfound = false;
             } 
             else if (row == 2){ //จากด้านบน ถ้าได้ row ตามนี้ให้ทำข้างล่าง
              if (isfound and find(row2.begin(), row2.end() , word) != row2.end()){//ถ้าตัวอักษรยังอยู่ใน row อยู่เเละ ยังเจออยู่ 
                  isfound = true;
              } else isfound = false;
             }
              else if (row == 3){ //จากด้านบน ถ้าได้ row ตามนี้ให้ทำข้างล่าง
              if (isfound and find(row3.begin(), row3.end() , word) != row3.end()){//ถ้าตัวอักษรยังอยู่ใน row อยู่เเละ ยังเจออยู่ 
                  isfound = true;
            }else isfound = false;
          }
          }
           }
           if (isfound){
            result.push_back(words[i]);
           }
         }
         return result;
     }
};