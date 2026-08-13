#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* result = new ListNode;
                  result->next = head;
        ListNode* prev = result;
        ListNode* currectly = head;
            while(currectly != nullptr){
                if (currectly->val == val){
                  prev->next = currectly->next;
                  currectly = currectly->next;
                } else prev = prev->next , currectly = currectly->next;

            }
        return result->next;
    }
};