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
    int calPoints(vector<string>& operations) {
        vector<int> result;
        for (int i = 0; i < operations.size();i++){
            if (operations[i] == "+"){ // เอาscoreล่าสุดกับก่อนล่าสุด + กัน
                result.push_back(result.back() + result[result.size()-2]);
            }else if (operations[i] == "D"){ // 2  * score ล่าสุด
                result.push_back(result.back() * 2);
            }else if (operations[i] == "C"){ //ลบ score ล่าสุด
                result.pop_back();
            }else result.push_back(stoi(operations[i])); //push ตัวเลขเข้า
        }
        return accumulate(result.begin(),result.end(),0);
        //มีหน้าที่ สะสมค่าของสมาชิกในช่วง Iterator[จุดที่เรากำหนด] ที่เรากำหนด เช่น เริ่มสุดจนท้ายสุด
        //ตัวที่ 2 ถึงท้ายสุด
    }
};

class Solution { //ใช้ stack
public:
    int calPoints(vector<string>& operations) {
        stack<int> A;
        int total = 0;
       for (string dragon : operations){
        if (dragon == "D"){
            int last = A.top();
            A.push(last * 2);
            total += last * 2;
        }else if (dragon == "C"){
            int last = A.top();
            A.pop();
            total -= last;
        }else if (dragon == "+"){
            int last = A.top();
            A.pop();
            int lastprev = A.top();
            A.push(last);
            A.push(last + lastprev);
            total += last + lastprev;
        }else {
            int last = stoi(dragon);
            A.push(last) , total += last;
        }
       }
       return total;
    }
};