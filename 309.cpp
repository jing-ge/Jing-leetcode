// 309. Best Time to Buy and Sell Stock with Cooldown
// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
// After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
// Example:

// Input: [1,2,3,0,2]
// Output: 3 
// Explanation: transactions = [buy, sell, cooldown, buy, sell]



#include <iostream>
#include <vector>

using namespace std;


void print(int dp[][2],int m, int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<",";
        }
        cout<<endl;
    }
}


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0)return 0;
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[1][0] = 0;
        dp[1][1] = -prices[0];
        for(int i=2;i<=n;i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i-1]);
            dp[i][1] = max(dp[i-1][1],dp[i-2][0]-prices[i-1]);
        }
        return dp[n][0]>0?dp[n][0]:0;
    }
};

int main(){
    Solution s = Solution();
    vector<int> prices = {1,2,3,0,2};
    int res = s.maxProfit(prices);
    cout<<res<<endl;
    return 0;
}