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
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total = 0;
        int gap = 0;
        for (int i = 1; i < timeSeries.size();i++){ // วนตาม size
            gap = timeSeries[i] - timeSeries[i - 1]; // หาช่องว่างระหว่าง curr attack - prev attack
            if (gap < duration){ // attack posion มาเร็วจนพิษเก่ายังไม่หมด
                total += gap;  // เพราะงั้นให้มัน ให้มันเอาช่อง gap มาทับได้เลย
            } else total += duration; // attack posion พิษไม่ทับกัน
        }
        total += duration; // เพราะว่าผิดไม่ทับกันให้ + เวลาเพิ่มไปจากอันเก่าได้เลย
                           // นับ poison ของ attack ครั้งสุดท้ายเต็ม duration
        return total;
    }
};