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
    double helper(vector<int>&p1 ,vector<int>&p2,vector<int>&p3){
        return 0.5* abs( 1 *
            p1[0] * (p2[1] - p3[1]) +
            p2[0] * (p3[1] - p1[1]) +
            p3[0] * (p1[1] - p2[1])
        ); // สูตร
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double ans = 0;
        for (int i = 0; i < n - 2;i++){ // กำหนดเเบบนี้เพราะไม่อยากให้มีจุดซ้ำ
            for (int j = i + 1;j < n - 1;j++){ // กำหนดเเบบนี้เพราะไม่อยากให้มีจุดซ้ำ
                for (int k = j + 1; k < n;k++){ // กำหนดเเบบนี้เพราะไม่อยากให้มีจุดซ้ำ
                    double area = helper(points[i] , points[j] , points[k]);
                    ans = max(ans , area);
                }
            }
        }
        return ans;
    }
};

class Solution { // Cross Product ใช้ vector เเทนสูตร เเต่สูตรเหมือนกันนะ
public:
    double helper(vector<int>&p1 ,vector<int>&p2,vector<int>&p3){
        int ab_x = p2[0] - p1[0];
        int ab_y = p2[1] - p1[1];
        int ac_x = p3[0] - p1[0];
        int ac_y = p3[1] - p1[1];
        return 0.5 * abs((1.0 * ab_x * ac_y) - (1.0 * ab_y * ac_x));
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double ans = 0;
        for (int i = 0; i < n - 2;i++){ 
            for (int j = i + 1;j < n - 1;j++){ 
                for (int k = j + 1; k < n;k++){ 
                    double area = helper(points[i] , points[j] , points[k]);
                    ans = max(ans , area);
                }
            }
        }
        return ans;
    }
};