#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newnode = new ListNode;
        ListNode* Result = newnode;
        ListNode* Tail = newnode;
        int carry = 0;
        int digit;
            while (l1 != nullptr || l2 != nullptr){
                int value = (l1 == nullptr)? 0 : l1->val;
                int value2 = (l2 == nullptr)? 0 : l2->val;
                 int sum = carry + value + value2;
                 digit = sum % 10;
                 carry = sum / 10;
                Tail->next = new ListNode(digit);
                Tail = Tail->next;
                if (l1 != nullptr){
                    l1 = l1->next;
                }
                if (l2 != nullptr){
                    l2 = l2->next;
                }
            }
             if (carry != 0 ){
                    Tail->next = new ListNode(carry);
                    Tail = Tail->next;
                }
                return Result->next;
    }
};