// 714. Best Time to Buy and Sell Stock with Transaction Fee

// Your are given an array of integers prices, for which the i-th element is the price of a given stock on day i; and a non-negative integer fee representing a transaction fee.

// You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)

// Return the maximum profit you can make.

// Example 1:
// Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
// Output: 8
// Explanation: The maximum profit can be achieved by:
// Buying at prices[0] = 1
// Selling at prices[3] = 8
// Buying at prices[4] = 4
// Selling at prices[5] = 9
// The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
// Note:

// 0 < prices.length <= 50000.
// 0 < prices[i] < 50000.
// 0 <= fee < 50000.


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
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if(n==0)return 0;
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0]-fee;
        for(int i=1;i<=n;i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i-1]);
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]-prices[i-1]-fee);
        }
        return dp[n][0]>0?dp[n][0]:0;
    }
};

int main(){
    Solution s = Solution();
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;
    int res = s.maxProfit(prices,fee);
    cout<<res<<endl;
    return 0;
}