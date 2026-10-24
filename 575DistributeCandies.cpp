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
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> issame;
        for (int candy : candyType){
            issame.insert(candy);
        }
        return min(candyType.size() / 2 , issame.size()) ;
    }
};