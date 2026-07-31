#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
using namespace std; 
class Solution {
public:
    vector<int> getRow(int rowIndex) {
       vector<int> prevline;

        for(int i = 0; i <= rowIndex ; i++){
            vector<int> currentRows (i + 1);     
            currentRows[0] = 1 , currentRows[currentRows.size()- 1] = 1;      
            
            for (int j = 1; j < (int)currentRows.size() - 1;j++){
                currentRows[j] = prevline[j-1] + prevline[j];
            }
     
            prevline = currentRows;
        }
        return prevline;
    }
};