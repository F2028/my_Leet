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
using namespace std;
class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0; //เอาไว้คิดเเนว นอน
        int y = 0; //เอาไว้คิดเเนวตั้ง
        // เเนวคิดคือ ถ้า x เเละ y == 0 robot กลับมาอยู่จุดเดิม
        //ถ้าไม่คือผิด
        for (int i = 0; i < moves.length();i++){
            if (moves[i] == 'L') x++;
            if (moves[i] == 'R') x--;
            if (moves[i] == 'U') y++;
            if (moves[i] == 'D') y--;
            
        }
        return x == 0 and y == 0;
    }
};