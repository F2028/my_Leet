#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;    
class Solution {
public:
    string addBinary(string a, string b) {
       int i = a.size() -1;
       int j = b.size() -1;
       int carry = 0;
       string result = "" ;
       while (i >= 0 || j >= 0 || carry > 0){
           int digitA = (i >= 0) ? (a[i] - '0') : 0;   // เอา char มาลบกัน ถ้ามีเลข a[1] - 0 = 1 ไม่จริงก็ เอา 0 ไป
           int digitB = (j >= 0) ? (b[j] - '0') : 0;  
           
           int sum = digitA + digitB + carry;   // why plus carry? cuz เราต้องเอา carry[ตัวทด] มาบวกด้วย (ของรอบที่เเล้ว)
           int bit = sum % 2;   // คือเอาไว้เก็บชั่วคราว เก็บ sum
           carry = sum / 2;     // why make it this line? why not make it at first เพราะว่า เราต้องรอให้ sum คำนวนก่อนเเล้วค่อนเอาค่านี้ไปบวกทีหลัง(รอบหน้า)
            result += to_string(bit);
            i--,j--;
        }
        reverse(result.begin() , result.end());
       return result;
    }
};
int main() {
    Solution sol;
    cout << sol.addBinary("11", "1") << endl;       // ควรได้ "100"
    cout << sol.addBinary("1010", "1011") << endl;   // ควรได้ "10101"
    return 0;
}