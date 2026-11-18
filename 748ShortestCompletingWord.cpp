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
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int plate[26] = {};
        for (char a : licensePlate){ //วนทีละตัวเพื่อนเอามาเช็ค
            if (isalpha(a)) plate[tolower(a) - 'a']++; //เอามาที่ละตัว
            // ++ คือบวกช่องของ array ไปเพิ่ม
        }
        string toon = "";
        for (string b : words){ // วนคำ
            int woord[26] = {}; // เอามาข้างในเพื่อให้ reset ทุกคำ
            bool pass = true; //กันไว้เพื่อกำหนดว่าคำนี้ ผ่านนะมีทุกตัวอยู่
            for (char c : b){ //วนทีละตัวของ คำ
                woord[c - 'a']++; //เอามาทีละตัวเหมือนกัน
            }
            for (int i = 0 ; i < 26;i++){
                if (woord[i] < plate[i]) pass = false;
                // เช็คว่าคำ(word) มีตัวมากพอสำหรับ plate ให้เช็คไหม ง่ายๆก็คือเช็คว่าเหมือนกันไหม
            }
            if (pass and (toon.empty() or b.size() < toon.size())) toon = b;
            // คำตอบยังไม่มีคำ ถ้าเกิด คำตอบ(toon) มีคำเเล้วเเต่เจอคำที่สั้นกว่า เลยให้คำ(toon) = คำ(b)
        }
        return toon;
    }
};