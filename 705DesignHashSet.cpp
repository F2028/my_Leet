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
class MyHashSet {
public:
    vector<bool> A;
    MyHashSet(): A(1000001 , false) {
    }
    
    void add(int key) {
        A[key] = true;
    }
    
    void remove(int key) {
        A[key] = false;
    }
    
    bool contains(int key) {
        return A[key];
    }
};

class MyHashSet { // hash fn and collision ไม่เคยทำ
public:
    int count = 1009;
    vector<vector<int>> buck;
    MyHashSet() {
        buck.resize(count); // resize เปลี่ยนขนาด size vector(n)
    }
    int hashfn (int key){
        return key % count; //สูตรหา index [key modulo count[จำนวนช่องที่มี]]
    }
    void add(int key) {
        int index = hashfn(key);
        for (int a : buck[index]){
            if (a == key){
                return;
            }
        }
        buck[index].push_back(key); //ดัน key เข้าไปใน buck[index] ที่เป็นช่องที่เรากำหนดไว้ไม่ใช่ทั้ง vector
    }
    
    void remove(int key) {
        int index = hashfn(key);
       auto A = buck[index].begin(); //กำหนด lterator ที่หัว
       while (A != buck[index].end()){ //ละเดินจากหัวไปท้าย
         if (*A == key){
            A = buck[index].erase(A); // ใช้เเบบนี้ก็ได้หรือ 
            // return; หลังจากลบ
         }else A++;
       }
    }
    
    bool contains(int key) {
        int index = hashfn(key);
        for (int a : buck[index]){
            if (a == key) return true;
        }
        return false;
    }
};