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
    int numJewelsInStones(string jewels, string stones) { //ต้องวันเช็คทุกตัว 2 loops
        int count = 0;
        for (int i = 0; i < stones.length();i++){ //เข็คตัวเเรกของ stones
            for (int j = 0; j < jewels.size();j++) // เช็คตัวเเรกเเละเรื่อยๆจนกว่าจบ loop j ค่อย + i เพิ่ม
            if (stones[i] == jewels[j]) {
                count++;
                break;
            }
        }
        return count;
    }
};

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) { // ใช้ find หา เเทนใช้ 2 loops
        int count = 0;
        for (int i = 0; i < stones.length();i++){
            if (jewels.find(stones[i]) != string::npos) { // stinrg::npos คือหาไม่เจอหรือจุดสิ้นสุด
                count++;
            }
        }
        return count;
    }
};

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> A(jewels.begin() , jewels.end()); // เก็บเป็น set ไม่ซ้ำกัน ของ jewels
        int count = 0;
        for (char a : stones){
            if (A.count(a)) count++; // ให้ unorderset A นับว่า มี char a กี่ตัวใน A
        }
        return count;
    }
};

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        bool A[128] = {}; // ปรับให้เป็น fales ทุกตัว 128 , ทำไม 128? เพราะมันคือ ASCII 128 ตัว 'a' -> 'Z'
        for (char a : jewels){ // set ค่าให้ A[a] เป็น true
            A[a] = true;
        }
        int count = 0;
        for (char a : stones){ 
            if (A[a]) count++; // เเล้ว check ว่า true กี่ตัว
        }
        return count;
    }
};