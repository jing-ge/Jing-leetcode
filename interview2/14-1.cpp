// 剑指 Offer 14- I. 剪绳子
// 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

// 示例 1：

// 输入: 2
// 输出: 1
// 解释: 2 = 1 + 1, 1 × 1 = 1
// 示例 2:

// 输入: 10
// 输出: 36
// 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36
// 提示：

// 2 <= n <= 58
// 注意：本题与主站 343 题相同：https://leetcode-cn.com/problems/integer-break/

// 通过次数134,727提交次数237,486

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int cuttingRope_(int n) {
        if(n<=3)return n-1;
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int i=4;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i] = max(dp[j]*dp[i-j],dp[i]);
            }
        }
        return dp[n];
    }
    int cuttingRope(int n) {
        if(n<=3)return n-1;
        int a = n/3,b = n%3;
        if(b==0)return pow(3,a);
        if(b==1)return pow(3,a-1)*4;
        if(b==2)return pow(3,a)*2;
        return 0;
    }
};

int main(){
    int n = 10;
    Solution s;
    int res = s.cuttingRope(n);
    cout<<res<<endl;
    return 0;
}