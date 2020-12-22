// 面试题 08.01. Three Steps Problem LCCIA child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time. Implement a method to count how many possible ways the child can run up the stairs. The result may be large, so return it modulo 1000000007.

// Example1:

//  Input: n = 3 
//  Output: 4
// Example2:

//  Input: n = 5
//  Output: 13
// Note:

// 1 <= n <= 1000000


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int waysToStep(int n) {
        vector<int> dp;
        if(n<3){
            dp = vector<int>(4,0);
            dp[0] = 0;
            dp[1] = 1;
            dp[2] = 2;
            dp[3] = 4;
        }else{
            dp = vector<int>(n+1,0);
            dp[0] = 0;
            dp[1] = 1;
            dp[2] = 2;
            dp[3] = 4;
            for(int i=4;i<=n;i++){
                dp[i] = ((dp[i-1] + dp[i-2])%1000000007 + dp[i-3])%1000000007; 
            }
        }
        return dp[n];
    }
    int waysToStep2(int n) {
        if(n<3)return n;
        int base = 1e9+7,dp0 = 1,dp1 = 2,dp2 =4,tmp1,tmp2;
        while(n--!=3){
            tmp1 = dp1;
            tmp2 = dp2;
            dp2 = ((dp0+dp1)%base+dp2)%base;
            dp1 = tmp2;
            dp0 = tmp1;
        } 
        return dp2;
    }
};

int main(){
    Solution s = Solution();
    int res = s.waysToStep2(200);
    cout<<res<<endl;
    return 0;
}