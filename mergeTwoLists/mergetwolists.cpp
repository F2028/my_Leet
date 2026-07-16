#include <iostream>
#include <unordered_map>
#include <map>
#include <stack>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
using namespace std;
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            // list1 compare to list2 find min
            // create dummy roll cuz we need ไอ่ตัวว่างอะเพื่อให้ตัวที่น้อยสุดเข้าไปในนั้น
            // loop ended when one of the list have no value,null then we compare what we left in list compare to the list that we sorted
            ListNode dummy;
            ListNode* current = &dummy;
                // ทำให้เหลือ เเค่ list เดียว
            while (list1 != nullptr && list2 != nullptr){
                if (list1->val < list2->val){       // เทียบค่า
                    current->next = list1;          // เอา list1 เข้าไป
                   list1 = list1->next;         // ขยับ list1 ไปข้างหน้า
                }else {
                    current->next = list2;
                    list2 = list2->next;
                }
                current = current->next;        // ขยับไปข้างหน้า  
                    // เอา list ที่เหลือยัดเข้าไป
            }
            if (list1 == nullptr){              // ได้อีกเเบบ เช่น while(list1) (condition)
                current->next = list2;          
            } else {                                // current -> next = (list1 == nullptr) ? list2 : list1
                 current->next = list1;             // เราไม่จำเป็นต้องมีหรอ???
            }
            return dummy.next;
    }
};