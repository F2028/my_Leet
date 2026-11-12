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

class MyHashSet { // open addresing
public:
    static constexpr int cap = 2000003;
    static constexpr int empty = -1; //เอาไว้ ดูว่ามันว่างไหม -1 ไม่มีอยู่ใน vector , index จริง
    static constexpr int deleted = -2; // คือเอาไว้ลบ -1 เอาไว้กำหนดช่องว่าง
    vector<int> A;
    MyHashSet() : A(cap , empty) {
        
    }

     int hash(int key){
        return key % cap; //formula key mod buck
    }
    
    void add(int key) {
        int deleteindex = -1;
        for (int i = 0 ; i < cap ;i++){
            int index = (hash(key) + i) % cap;
            if (A[index] == key) return; //ถ้าเกิดเจอ key อยู่ใน index อยู่เเล้ว return เพราะ dup
            if (A[index] == deleted and deleteindex == -1) { //ในกรณีที่มันถูกลบไปเเล้ว
                deleteindex = index; //ให้ จำค่า index ไว้ เพิ่ม add ทีหลัง
            }
            if (A[index] == empty){ // ถ้าช่องว่าง
                int cur = (deleteindex != -1) ? deleteindex : index; // if - else short cut
                // ให้ดูว่า ไอ่ค่าทีถูกลบถูกจำไว้ไหมถ้าใช้ ให้ใช้ index อันนั้น add(key) เข้าไป ถ้าไม่ ให้ใช้ index ปัจจุบัน
                A[cur] = key;
                return;
              }
            }
            if (deleteindex != -1){ // เอาไว้กัน edge case เผื่อหลุดมา
                A[deleteindex] = key;
        }
    }
    
    void remove(int key) { // ลบ ดูเเค่ เจอ key , keyว่าง ให้ return กลับ
        for (int i = 0 ; i < cap ;i++){
            int index = (hash(key) + i) % cap;
            if (A[index] == key) { // ถ้าเจอ
                A[index] = deleted; // ลบ
                return ;
            }
            if (A[index] == empty){ //ช่องมันว่าง return เพราะไม่มีไรให้ลบ 
                return;
            }
        }
    }
    
    bool contains(int key) { // เช็คว่ามีเลขนั้นจริงรึไม่
        for (int i = 0 ; i < cap ;i++){
            int index = (hash(key) + i) % cap;
            if (A[index] == key) return true; // ถ้าเจอ return true;
            } 
            return false;
        }  
};