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
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (int i = 0 ; i < letters.size();i++){
            if (letters[i] > target){
                return letters[i];
            }
        }
        return letters[0];
    }
};