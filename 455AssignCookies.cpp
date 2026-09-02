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
    int findContentChildren(vector<int>& g, vector<int>& s) {
      sort(g.begin(),g.end());
      sort(s.begin(),s.end());
      int count = 0; // use when we need it to return
      int left = 0; //child
      int right = 0; // cookies
      while (left < g.size() and right < s.size()){ // วนจนกว่าจะมี cookie and child พอที่จะหา
        if (g[left] > s[right]){ // เด็กไม่อยากกิน cookieที่น้อยกว่า
            right ++; //เลย ++ cookie
        }else left++ , right++ ,count++; // ถ้าcookie >= เด็กพอใจกินอร่อย
      }
      return count;
    }
};