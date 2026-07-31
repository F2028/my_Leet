#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
using namespace std; 
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       vector <vector<int>> lines;

        for(int i = 0; i < numRows ; i++){
            vector<int> values (i + 1);     // การจองที่ไว้
            values[0] = 1 , values[values.size()- 1] = 1;       // เเล้วเอาค่าไปเเทนช่องต่างๆ
            for (int j = 1; j < (int)values.size() - 1; j++){   // เเล้วเอาค่าไปเเทนช่องต่างๆ
                values[j] = lines[i-1][j-1] + lines[i-1][j];
            }

            lines.push_back(values);    // ดันค่าทั้งหมดของ values เข้า lines
        }
        return lines;
    }
};