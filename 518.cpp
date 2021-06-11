#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1);
        dp[0]=1;
        for(int& coin:coins){
            for(int i=coin;i<=amount;i++){
                dp[i]+=dp[i-coin];
            }
        }
        return dp[amount];
    }
};

int main(){
    Solution s;
    vector<int> coins = {1,2,5};
    int amounts = 5;
    int res = s.change(amounts,coins);
    cout<<res<<endl;
}