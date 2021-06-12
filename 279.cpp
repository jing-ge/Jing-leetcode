// 279. Perfect Squares
// Given an integer n, return the least number of perfect square numbers that sum to n.

// A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

 

// Example 1:

// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.
// Example 2:

// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.
 

// Constraints:

// 1 <= n <= 104
// 通过次数161,488提交次数260,547

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int numSquares_dp(int n) {
        vector<int> dp(n+1);
        for(int i=1;i<=n;i++){
            int minn = INT_MAX;
            for(int j=1;j*j<=i;j++){
                minn = min(minn,dp[i-j*j]);
            }
            dp[i] = minn+1;
        }
        return dp[n];
    }

    //         方法二：数学
        // 思路及算法

        // 一个数学定理可以帮助解决本题：「四平方和定理」。

        // 四平方和定理证明了任意一个正整数都可以被表示为至多四个正整数的平方和。这给出了本题的答案的上界。

        // 同时四平方和定理包含了一个更强的结论：当且仅当 n \neq 4^k \times (8m+7)n 
        // 
        // ​	
        //  =4 
        // k
        //  ×(8m+7) 时，nn 可以被表示为至多三个正整数的平方和。因此，当 n = 4^k \times (8m+7)n=4 
        // k
        //  ×(8m+7) 时，nn 只能被表示为四个正整数的平方和。此时我们可以直接返回 44。

        // 当 n \neq 4^k \times (8m+7)n 
        // 
        // ​	
        //  =4 
        // k
        //  ×(8m+7) 时，我们需要判断到底多少个完全平方数能够表示 nn，我们知道答案只会是 1,2,31,2,3 中的一个：

        // 答案为 11 时，则必有 nn 为完全平方数，这很好判断；

        // 答案为 22 时，则有 n=a^2+b^2n=a 
        // 2
        //  +b 
        // 2
        //  ，我们只需要枚举所有的 a(1 \leq a \leq \sqrt{n})a(1≤a≤ 
        // n
        // ​	
        //  )，判断 n-a^2n−a 
        // 2
        //   是否为完全平方数即可；

        // 答案为 33 时，我们很难在一个优秀的时间复杂度内解决它，但我们只需要检查答案为 11 或 22 的两种情况，即可利用排除法确定答案。

    // 判断是否为完全平方数
    bool is_square(int n){
        int t = sqrt(n);
        return t*t==n;
    }

    // 判断是否能表示为 4^k*(8m+7)
    bool is_4(int n){
        while(n%4==0){
            n /= 4;
        }
        return n%8==7;
    }

    int numSquares(int n){
        if(is_square(n))return 1;
        if(is_4(n))return 4;
        for(int i=1;i*i<=n;i++){
            int j = n-i*i;
            if(is_square(j))return 2;
        }
        return 3;
    }
};

int main(){
    Solution s;
    int n = 12;
    int res = s.numSquares(n);
    cout<<res<<endl;
    return 0;
}