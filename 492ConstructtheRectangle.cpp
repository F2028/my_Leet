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
using namespace std;        
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = sqrt(area); // หา rootมาก่อนเเทนที่จะหา forloop (i) เเล้วคูณทีละตัว
        while (area % w != 0){ // ถ้าหาเเล้วไม่เท่าให้ width ลดลงเรื่อยๆ
            w--;
        }
        int l = area / w; // หา length (formula)
        return {l , w};
    }
};