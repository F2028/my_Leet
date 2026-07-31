#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
using namespace std; 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int bestProfit = 0;
        for(int i = 0; i < prices.size();i++){
             int profit = 0;

           if(prices[i] < minPrice){
             minPrice = prices[i];
           }
           profit = prices[i] - minPrice;
           if (profit > bestProfit){
                bestProfit = profit;
           }
        }
        return bestProfit;
    }
};