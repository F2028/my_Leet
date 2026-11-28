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
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string , int> ans;
        string word = "";
        string result = "";
        int count = 0;
        for (char a : paragraph){
            a = tolower(a);
            if (isalnum(a)){
            word += a;
            } else {
                if (word != "") ans[word]++ , word = "";
            }
        }
        if (word != "") ans[word]++ , word = "";
        for (string b : banned){
            ans.erase(b);
        }
        for (auto [key,value] : ans){
            if (value > count) count = value , result = key;
        }
        return result;
    }
};