// 121. Best Time to Buy and Sell Stock
// Say you have an array for which the ith element is the price of a given stock on day i.

// If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

// Note that you cannot sell a stock before you buy one.

// Example 1:

// Input: [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
//              Not 7-1 = 6, as selling price needs to be larger than buying price.
// Example 2:

// Input: [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.


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
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i=1;i<=n;i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i-1]);
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]-prices[i-1]);
        }
        return dp[n][0]>0?dp[n][0]:0;
    }
};

int main(){
    Solution s = Solution();
    vector<int> prices = {7,1,5,3,6,4};
    int res = s.maxProfit(prices);
    cout<<res<<endl;
    return 0;
}