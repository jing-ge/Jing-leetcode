// 552. Student Attendance Record II
// An attendance record for a student can be represented as a string where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:

// 'A': Absent.
// 'L': Late.
// 'P': Present.
// Any student is eligible for an attendance award if they meet both of the following criteria:

// The student was absent ('A') for strictly fewer than 2 days total.
// The student was never late ('L') for 3 or more consecutive days.
// Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. The answer may be very large, so return it modulo 109 + 7.

 

// Example 1:

// Input: n = 2
// Output: 8
// Explanation: There are 8 records with length 2 that are eligible for an award:
// "PP", "AP", "PA", "LP", "PL", "AL", "LA", "LL"
// Only "AA" is not eligible because there are 2 absences (there need to be fewer than 2).
// Example 2:

// Input: n = 1
// Output: 3
// Example 3:

// Input: n = 10101
// Output: 183236316
 

// Constraints:

// 1 <= n <= 105
// 通过次数12,456提交次数23,088
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3)));
        int mod = 1000000007;
        dp[0][0][0]=1;
        for(int i=1;i<=n;i++){
            //今天0次缺席，0次连续迟到，过去也一定是0次缺席，但可以是0，1，2次连续迟到
            dp[i][0][0] = (dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2])%mod; 
            //今天0次缺席，1次连续迟到，过去也一定是0次缺席，0次迟到
            dp[i][0][1] = dp[i-1][0][0]%mod;
            //今天0次缺席，2次连续迟到，过去也一定是0次缺席，1次迟到
            dp[i][0][2] = dp[i-1][0][1]%mod;
            //今天1次缺席，0次连续迟到:（1）过去0次缺席，0次迟到，今天缺席了（2）过去1次缺席，0次迟到，今天没缺席
            dp[i][1][0] = (dp[i-1][1][0] + dp[i-1][1][1]+dp[i-1][1][2] +dp[i-1][0][0] + dp[i-1][0][1] +dp[i-1][0][2])%mod;
            //今天1次缺席，1次连续迟到:过去1次缺席，0次迟到，今天迟到
            dp[i][1][1] = dp[i-1][1][0]%mod;
            //今天1次缺席，2次连续迟到:过去1次缺席，1次迟到，今天迟到
            dp[i][1][2] = dp[i-1][1][1]%mod;
        }
        return dp[n][0][0] + dp[n][0][1] + dp[n][0][2] + dp[n][1][0] + dp[n][1][1] + dp[n][1][2] ;
    }
};

int main(){
    Solution s;
    int n = 2;
    int res = s.checkRecord(n);
    cout<<res<<endl;
    return 0;
}