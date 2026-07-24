#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
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
    ListNode* deleteDuplicates(ListNode* head) {
            ListNode* current = head;           // สร้าให้เป็นตัวเริ่มต้น
            while (current != nullptr && current->next!= nullptr ){
                    if (current->val == current->next->val){    // ถ้าเหมือน ให้ข้าม
                        current->next = current->next->next;    // ข้ามเเม่งS
                    } else current = current->next;             // ไม่เท่าอ่อ ให้เก็บไว้
            }
            return head;        //เราreturn head เพราะ node ข้างใน head ถูกเเก้ไข
    }
};