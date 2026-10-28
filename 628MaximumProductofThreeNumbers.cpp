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
using namespace std;
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
       vector<int> A = nums;
       int a = 0;
       int b = 0;
       sort(A.begin(),A.end());
        a = A[A.size()-1] * A[A.size()-2] * A[A.size()-3];
       if (A[0] * A[1] > 0){
        b = A[0] * A[1] * A[A.size()-1];
        if (b > a) {
          return b;
        }
       }
        
       return a;
    }
};