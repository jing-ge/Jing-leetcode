// 188. Best Time to Buy and Sell Stock IV
// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

// Design an algorithm to find the maximum profit. You may complete at most k transactions.

// Notice that you may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

//  

// Example 1:

// Input: k = 2, prices = [2,4,1]
// Output: 2
// Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
// Example 2:

// Input: k = 2, prices = [3,2,6,5,0,3]
// Output: 7
// Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.



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
    int maxProfit(int K,vector<int>& prices) {
        int n = prices.size();
        if(n==0)return 0;
        if(K>n/2)return maxProfit(prices);
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(K+1,vector<int>(2,0)));
        for(int i=K;i>=1;i--){
            dp[0][i][0] = 0;
            dp[0][i][1] = -prices[0];
        }
        for(int i=1;i<=n;i++){
            for(int k=K;k>=1;k--){
                dp[i][k][0] = max(dp[i-1][k][0],dp[i-1][k][1]+prices[i-1]);
                dp[i][k][1] = max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i-1]);
            }
            
        }
        return dp[n][K][0]>0?dp[n][K][0]:0;
    }
};

int main(){
    Solution s = Solution();
    int k=2;
    vector<int> prices = {3,2,6,5,0,3};
    int res = s.maxProfit(k,prices);
    cout<<res<<endl;
    return 0;
}