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
using namespace std;        
 class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> nosorted = score;
        vector<string> answer;
        sort(nosorted.begin(),nosorted.end() , greater<int>()); //มาก -> น้อย
        unordered_map<int , int> rank;
        for (int i = 0; i < score.size();i++){
            rank[nosorted[i]] = i + 1; // เอา nosorted เป็น key (คะเเนน) ส่วนอันดับเป็น value
        }
        for (int i = 0; i < score.size();i++){
            if (rank[score[i]] == 1){  // ถ้าที่ 1
                answer.push_back("Gold Medal");
            } else if (rank[score[i]] == 2){    //ถ้าที่ 2
                answer.push_back("Silver Medal");
            } else if (rank[score[i]] == 3){ //ถ้าที่ 3
                answer.push_back("Bronze Medal");
            } else
              answer.push_back(to_string(rank[score[i]])); //เปลี่ยนเป็น string เเละ pushback
        }
        return answer;
    }
};