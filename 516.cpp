// 516. Longest Palindromic Subsequence
// Given a string s, find the longest palindromic subsequence's length in s.

// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

// Example 1:

// Input: s = "bbbab"
// Output: 4
// Explanation: One possible longest palindromic subsequence is "bbbb".
// Example 2:

// Input: s = "cbbd"
// Output: 2
// Explanation: One possible longest palindromic subsequence is "bb".
 

// Constraints:

// 1 <= s.length <= 1000
// s consists only of lowercase English letters.
// 通过次数69,051提交次数107,853

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq_(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]){
                    dp[i][j] = dp[i+1][j-1]+2;
                }else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
    int longestPalindromeSubseq__(string s) {
        int N = s.size();
        vector<vector<int>> dp(N,vector<int>(N,0));
        for(int i=0;i<N;i++){
            dp[i][i]=1;
        }
        int m,n;
        for(int i=1;i<N;i++){
            for(int j=0;j<N-i;j++){
                m = j,n = j+i;
                if(s[m]==s[n]){
                    dp[m][n] = dp[m+1][n-1] +2;
                }else{
                    dp[m][n] = max(dp[m+1][n],dp[m][n-1]);
                }
            }
        }
        return dp[0][N-1];
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        int i;
        for(int N=1;N<n;N++){
            i=0;
            for(int j=i+N;j<n;j++){
                // cout<<i<<","<<j<<endl;
                if(s[i]==s[j]){
                    dp[i][j] = dp[i+1][j-1]+2;
                }else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                }
                i++;
            }
        }
        return dp[0][n-1];
    }
};

int main(){
    Solution s;
    string str =  "bbbab";
    int res = s.longestPalindromeSubseq(str);
    cout<<res<<endl;
    return 0;
}