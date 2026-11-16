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
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        while (i < bits.size() - 1){ // we use - 1 cuz เราไม่ต้องการให้มันรวมตัวสุดท้าย
            if (bits[i] == 0){
                i++;
            }else i += 2;
        }
        return i == bits.size() - 1; //เช็ค
    }
};

class Solution { // use math 
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        int size = bits.size(); // if we store some value that need to calculate more than 1
        // its better to store it to save memory
        while (i < size - 1){
            i += bits[i] + 1; // why worked?
            // cuz let say [1,0,0] if 1 + 1 = 2 , 0 + 1 = 1 its similair isnt it?
            //its like i++ , i+= 2 we use the value that it store to calculte
            // than calculate it ourself
        }
        return i == size - 1;
    }
};

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int count = 0;
        for (int i = bits.size() - 2; i >= 0 and bits[i] == 1;i--) count++;  
        // We start at the index immediately before the last element and move backwards 
        // while we encounter consecutive ones
        // we let count + 1 
        return count % 2 == 0;  
    }
};