// 264. Ugly Number II
// Given an integer n, return the nth ugly number.

// Ugly number is a positive number whose prime factors only include 2, 3, and/or 5.

 

// Example 1:

// Input: n = 10
// Output: 12
// Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
// Example 2:

// Input: n = 1
// Output: 1
// Explanation: 1 is typically treated as an ugly number.
 

// Constraints:

// 1 <= n <= 1690
// 通过次数61,061提交次数108,496

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1);
        dp[1] =1;
        int p2 =1,p3=1,p5=1;
        for(int i=2;i<=n;i++){
            int num2 = dp[p2]*2,num3 = dp[p3]*3,num5 = dp[p5]*5;
            dp[i]=min(min(num2,num3),num5);
            if(dp[i]==num2){
                p2++;
            }
            if(dp[i]==num3){
                p3++;
            }
            if(dp[i]==num5){
                p5++;
            }
        }
        return dp[n];
    }
};

int main(){
    Solution s;
    int n = 10;
    int res = s.nthUglyNumber(10);
    cout<<res<<endl;
    return 0;
}