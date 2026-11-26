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
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int totalcount = 0;
        int lines = 1;
        for (int i = 0; i < s.size();i++){
            if (totalcount + widths[s[i] - 'a'] <= 100){ //ถ้าบวกกันเเล้วไม่เกิน 100 หรือ =
                int index = s[i] - 'a'; // เรียงกันไปจาก a -> z ว่าควรใช้ index ไหน? ใช้ index ซ้ำกันได้
                //ไม่ใช่ตัวเเรกใช้ index 1 no no (index หมายถึงของ widths)
                totalcount += widths[index]; //บวกสะสมไป
            } else totalcount = widths[s[i] - 'a'] , lines++; // ให้ตัวสะสม = ค่าล่าสุดไม่ใช่ reset
            //บวกเเถวเพิ่มไป 1
        }
        return {lines , totalcount};
    }
};

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int total = 0;
        int line = 1;
        for (char a : s){
            int b = widths[a - 'a'];
            if (total + b > 100){
                line++;
                total = b;
            } else total += b;
        }
        return {line , total};
    }
};

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        pair<int , int> ans = {0 , 1}; // .second เก็บจำวนวน line first = total;
        for (char a : s){
            int b = widths[a -'a'];
            if (ans.first + b > 100){
                ans.second++;
                ans.first = b;
            } else ans.first += b;
        }
        return {ans.second , ans.first};
    }
};