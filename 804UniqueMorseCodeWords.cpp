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
        for (string A : words){ // วน 1 คน
            string temp = ""; // สร้างตัวที่เอาไว้รวม
            for (char a : A){ //วน 1 อักษรของ คำที่กำลัง loop อยู่
            int index = a - 'a'; // เอาอักษรมาลบกับ 'a' จะได้ index มา
            temp += word[index]; // เอามารวมร่างกัน
            }
            B.insert(temp);
        }
        return B.size(); // ทำได้เลยเพราะเก็บเป็น unordered set
    }
};

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string word[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",
        ".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        vector<string> ans;
        for (string A : words){
            string temp = "";
            for (char B : A){
                int index = B - 'a';
                temp += word[index];
            }
            ans.push_back(temp);
        }
        sort(ans.begin(),ans.end()); //เป็น vector เอามาเรียงกันก่อน
        ans.erase(unique(ans.begin() , ans.end()) , ans.end()); //ละลบตัวที่ซ้ำไป
        return ans.size();
    }
};

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string word[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",
        ".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> ans;
        for (string A : words){
            string temp = "";
            for (char B : A){
                int index = B - 'a';
                temp += word[index];
            }
            ans.insert(temp);
        }
        return ans.size();
    }
};