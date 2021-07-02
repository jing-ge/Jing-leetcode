// 1833. Maximum Ice Cream Bars
// It is a sweltering summer day, and a boy wants to buy some ice cream bars.

// At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible. 

// Return the maximum number of ice cream bars the boy can buy with coins coins.

// Note: The boy can buy the ice cream bars in any order.

 

// Example 1:

// Input: costs = [1,3,2,4,1], coins = 7
// Output: 4
// Explanation: The boy can buy ice cream bars at indices 0,1,2,4 for a total price of 1 + 3 + 2 + 1 = 7.
// Example 2:

// Input: costs = [10,6,8,7,7,8], coins = 5
// Output: 0
// Explanation: The boy cannot afford any of the ice cream bars.
// Example 3:

// Input: costs = [1,6,3,1,2,5], coins = 20
// Output: 6
// Explanation: The boy can buy all the ice cream bars for a total price of 1 + 6 + 3 + 1 + 2 + 5 = 18.
 

// Constraints:

// costs.length == n
// 1 <= n <= 105
// 1 <= costs[i] <= 105
// 1 <= coins <= 108
// 通过次数22,421提交次数29,579

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxIceCream_sort(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int t = 0,res = 0;
        for(int i:costs){
            t+=i;
            if(t<=coins){
                res++;
            }else
            {
                break;
            }
            
        }
        return res;
    }
    int maxIceCream_vec(vector<int>& costs, int coins) {
        vector<int> arr(100001,0);
        for(int &t:costs){
            arr[t]++;
        }
        int res = 0;
        for(int i=1;i<=100000;i++){
            if(arr[i]==0)continue;
            if(coins>=i){
                int curCnt = min(arr[i],coins/i);
                res+=curCnt;
                coins -= curCnt*i;
            }else{
                break;
            }
        }
        return res;
    }
    int maxIceCream(vector<int>& costs, int coins) {
        map<int,int> arr;
        for(int &t:costs){
            arr[t]++;
        }
        int res = 0;
        for(auto &t:arr){
            if(t.second==0)continue;
            if(coins>=t.first){
                int curCnt = min(t.second,coins/t.first);
                res+=curCnt;
                coins -= curCnt*t.first;
            }else{
                break;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> costs = {4,7,6,4,4,2,2,4,8,8};
    int coins = 41;
    int res = s.maxIceCream(costs,coins);
    cout<<res<<endl;
    return 0;
}