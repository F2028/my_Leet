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
using namespace std;
class Solution { //ใช้ sort
public:
    vector<int> findErrorNums(vector<int>& nums) {
         vector<int> A = nums;
         int missing = 0; //เก็บเลขที่หาย
         int dup = 0; //เก็บตัวซ้ำ
         sort(A.begin(),A.end()); //เรียงก่อน
         for (int i = 1; i < A.size();i++){
           if (A[i] == A[i-1]){  //ถ้าตัวนี้กะตัวนั้นซ้ำ
            dup = A[i]; //เก็บค่าไว้
           }
           if (A[i] - A[i-1] == 2){ 
            missing = A[i-1]+1;
            //ตรงนี้ถึงใช้ได้?? น่าจะเป็นเพราะถ้าหัว หรือ ทัายหายมันก็จะไม่เจอเเล้วไปเข้าอีก for เเทน
            //อีกอย่างคือเรา sort() ไว้เเล้ว
           }
         }
         for (int i = 0; i < A.size();i++){ //กรณี หัวหรือท้ายหาย
            if (A[0] != 1)  missing = 1;
            if (A[A.size()-1] != A.size()) missing = A.size();
         }
         return {dup , missing}; // return
    }
};