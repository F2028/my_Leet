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
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        for (int i = 0; i < stones.length();i++){
            for (int j = 0; j < jewels.size();j++)
            if (stones[i] == jewels[j]) {
                count++;
                break;
            }
        }
        return count;
    }
};

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        for (int i = 0; i < stones.length();i++){
            if (jewels.find(stones[i]) != string::npos) {
                count++;
            }
        }
        return count;
    }
};

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> A(jewels.begin() , jewels.end());
        int count = 0;
        for (char a : stones){
            if (A.count(a)) count++;
        }
        return count;
    }
};

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        bool A[128];
        for (char a : jewels){
            A[a] = true;
        }
        int count = 0;
        for (char a : stones){
            if (A[a]) count++;
        }
        return count;
    }
};