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
#include <climits>
#include <queue>
#include <stack>
#include <numeric>
using namespace std;
/*pq.push(x);  // Insert
pq.top();    // Read the smallest number
pq.pop();    // Remove the smallest number
pq.size();   // Get the number of elements */
class KthLargest {
public:
    int k;
    priority_queue<int , vector<int> , greater<int>> pq;
    KthLargest(int k, vector<int>& nums) :k(k) {//constructor give k[constuctor] = k[value in fn]
        for (int a : nums){
            pq.push(a);
            if (pq.size() > k){ // cuz we need largest numbers = k so if it more then we pop
            pq.pop(); //pop the smallest one
            }
        }

    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k){
            pq.pop();
        }
        return pq.top();
    }
};