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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr){   // เช็ค fast เพราะมันเร็วกว่า slow
            slow = slow->next;              //เปลี่ยนค่าทุกรอบ
            fast = fast->next->next;        //เปลี่ยนค่าทุกรอบ
            if (fast == slow){              // git restore --staged ........... ในการเอา commit สักอย่างออก
                return true;
            }
        }
        return false;
    }
};