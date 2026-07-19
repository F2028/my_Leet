#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;    
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;           // present index if .size it count numbers not index
        int length = 0;             // count how long last words

        while (s[i] == ' '){            // make it move to last words if it has space 
            i--;
        }
        while ( i >= 0 && s[i] != ' '){     // if not have count the words
            length++;
            i--;
        }
        return length;
    }
};