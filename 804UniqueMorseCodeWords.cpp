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
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> B;
        string word[26]= {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for (string A : words){
            string temp = "";
            for (char a : A){
            int index = a - 'a';
            temp += word[index];
            }
            B.insert(temp);
        }
        return B.size();
    }
};