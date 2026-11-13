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
class MyHashMap {
public:
    vector<int> A;
    MyHashMap(): A(1000001 , -1) {
        
    }
    
    void put(int key, int value) {
        A[key] = value;
    }
    
    int get(int key) {
        return A[key];
    }
    
    void remove(int key) {
        A[key] = -1;
    }
};
