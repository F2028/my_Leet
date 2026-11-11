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
class MyHashSet {
public:
    vector<bool> A;
    MyHashSet(): A(1000001 , false) {
    }
    
    void add(int key) {
        A[key] = true;
    }
    
    void remove(int key) {
        A[key] = false;
    }
    
    bool contains(int key) {
        return A[key];
    }
};