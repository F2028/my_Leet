#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std; 
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;

        while(a != b){
           a = (a == nullptr)? headB : a->next; // if เเบบง่าย
           b = (b == nullptr)? headA : b->next; 
        }
        return a;
    }
};