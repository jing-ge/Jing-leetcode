// 72. Edit Distance
// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character
 

// Example 1:

// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation: 
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
// Example 2:

// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation: 
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')
 

// Constraints:

// 0 <= word1.length, word2.length <= 500
// word1 and word2 consist of lowercase English letters.
// 通过次数104,817提交次数173,836

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        int **dp = new int*[m+1];
        for(int i=0;i<=m;i++){
            dp[i] = new int[n+1];
        }
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0){
                    dp[i][j] = j;
                }else if(j==0){
                    dp[i][j] = i;
                }else{
                    dp[i][j]=0;
                }
            }
        }

        //dp
        int min;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(word1[i]==word2[j]){
                    min = mymin(dp[i][j]-1,dp[i+1][j],dp[i][j+1]);
                }else{
                    min = mymin(dp[i][j],dp[i+1][j],dp[i][j+1]);
                }
                dp[i+1][j+1] = min+1;
            }
        }


        // for(int i=0;i<=m;i++){
        //     for(int j=0;j<=n;j++){
        //         cout<<dp[i][j]<<'\t';
        //     }
        //     cout<<endl;
        // }
        return dp[m][n];
    }
    int mymin(int a,int b,int c){
        int min;
        min = a<b?a:b;
        min = min<c?min:c;
        return min;
    }
};

int main(){
    string word1 = "intention", word2 = "execution";
    Solution s;
    int res = s.minDistance(word1,word2);
    cout<<res<<endl;
    return 0;
}