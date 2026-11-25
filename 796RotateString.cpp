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
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return (bool)0;
        for (int i = 0; i < s.size();i++){ // เก็บตัวเเรก
            char first = s[0];
            if (s == goal) return true;
            for (int j = 0; j < s.size()-1;j++){ // เอาไว้ shift ตัว char
                s[j] = s[j+1];
            }
            s[s.size()-1] = first; // เอาค่าไว้ท้าย
        }
        return false;
    }
};

class Solution { // เอามาต่อกัน เพราะจะได้ ทั้งข้างหน้า , ข้างหลังไปด้วยกัน -> s + s
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false; //ถ้าขนาดไม่เท่ากัน return false;
        return (s+s).find(goal) != string::npos; // npos คือจุดจบ , ตัวท้าย
    }
};

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if (n != goal.size()) return false;
        for (int i = 0 ;i < n; i++){
            int j = 0;
            while (j < n and s[(i+j) % n] == goal[j]){
        //% n ใช้ควบคุม index ให้วนกลับมาเริ่มต้นเมื่อถึงท้าย string ไม่ได้ใช้กับค่าตัวอักษร
        //สูตร modulo มีหน้าที่ทำให้เราเข้าถึงตัวอักษรตามลำดับการหมุน 
        //ส่วน == มีหน้าที่ตรวจว่าการหมุนนั้นตรงกับ goal หรือไม่
                j++;
            }
            if (n == j) return true;
        }
        return false;
    }
};