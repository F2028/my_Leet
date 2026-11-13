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
class MyHashMap { // standard access // Run 18% , Mem 29 %
public:
    vector<int> A;
    MyHashMap(): A(1000001 , -1) {
        
    }
    
    void put(int key, int value) {
        A[key] = value;
    }
    
    int get(int key) {
        return A[key];
    }
    
    void remove(int key) {
        A[key] = -1;
    }
};

class MyHashMap { // pair vector //Run = 20 Mem = 97%
public:
    vector<pair<int , int>> A;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
       for (int i = 0 ; i < A.size();i++){
             if (key == A[i].first){ //ถ้า key ใช่
                A[i].second = value; // ยัดค่า
                return ;
             }
       }
       A.push_back({key , value}); //ถ้ายังไม่มี key ใส่ key พร้อม value
    }
    
    int get(int key) {
        for (int i = 0; i < A.size();i++){
            if (A[i].first == key){ //เช็คว่า key ตรงไหนถ้าตรง
                return A[i].second; //ส่ง value กลับไป
            }
        }
        return -1; //ไม่เจอ return -1
    }
    
    void remove(int key) {
        for (int i = 0 ; i < A.size();i++){
            if (A[i].first == key){ //ถ้าตรง
                A.erase(A.begin() + i); //ลบ โดยใช่ lterator สำหรับ pair(คู่)
                return;
            }
        }
    }
};