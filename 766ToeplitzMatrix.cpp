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
                if (matrix[i][j] != matrix[i-1][j-1]) return false;
            }
        }
        return true;
    }
};