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
using namespace std;    
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> result;
        int left = 0;

        while (head){   // do untill head == null
                result.push_back(head->val);  //push to see all val in result
                head = head->next;      // move head to next to go back to push.back
        }
        int right = result.size() - 1;  // last index
        while(left < right){        // do untill left > right
            if (result[left] != result[right]){
                    return false;
                }
                // if not true then do below here
                 left++;
                right--;
        }
         return true;
    }
};