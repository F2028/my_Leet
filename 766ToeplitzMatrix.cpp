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
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int i = 1 ; i < matrix.size();i++){ // row
            for (int j = 1; j < matrix[0].size();j++){ // collum
                if (matrix[i][j] != matrix[i-1][j-1]) return false; // i - 1 , j - 1 เช็คด้านบนเเละด้านซ้าย
            }
        }
        return true;
    }
};
 // i = row , j = collum  [ row = บนล่าง collum = ซ้าย ขวา]
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int a = matrix.size();
        int b = matrix[0].size();
        if (a <= 1 or b <= 1) return true; 
        for (int k = b + 1; k < a * b;k++){ // สูตร Flatten Matrix
            int i = k / b; // แปลง Index กลับเป็น Row
            int j = k % b; // index -> collum
            if (j == 0) continue; // ข้ามตำเเหน่ง 0 ข้ามคอลัมน์แรกของแต่ละแถวเพราะไม่มีช่องด้านบนซ้ายให้เปรียบเทียบ
            if (matrix[i][j] != matrix[i-1][j-1]) return false;
        }
        return true;
    }
};