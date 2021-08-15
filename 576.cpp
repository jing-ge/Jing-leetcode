// 576. Out of Boundary Paths
// There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

// Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.

 

// Example 1:


// Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
// Output: 6
// Example 2:


// Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
// Output: 12
 

// Constraints:

// 1 <= m, n <= 50
// 0 <= maxMove <= 50
// 0 <= startRow < m
// 0 <= startColumn < n
// 通过次数17,406提交次数39,141

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPaths_(int m, int n, int maxMove, int startRow, int startColumn) {
        int res = 0;
        int MOD = 1000000007;
        vector<vector<vector<int>>> dp(maxMove+1,vector<vector<int>>(m,vector<int>(n)));
        vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
        dp[0][startRow][startColumn] = 1;
        for(int i=0;i<maxMove;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<n;k++){
                    if(dp[i][j][k]>0){
                        for(auto &t:dir){
                            int j1 = j+t[0],k1 = k+t[1];
                            if(j1>=0&&j1<m&&k1>=0&&k1<n){
                                dp[i+1][j1][k1] = (dp[i+1][j1][k1]+dp[i][j][k])%MOD;
                            }else{
                                res = (res+dp[i][j][k])%MOD;
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int res = 0;
        int MOD = 1000000007;
        vector<vector<int>> dp(m,vector<int>(n));
        vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
        dp[startRow][startColumn] = 1;
        for(int i=0;i<maxMove;i++){
            vector<vector<int>> ndp(m,vector<int>(n));
            for(int j=0;j<m;j++){
                for(int k=0;k<n;k++){
                    if(dp[j][k]>0){
                        for(auto &t:dir){
                            int j1 = j+t[0],k1 = k+t[1];
                            if(j1>=0&&j1<m&&k1>=0&&k1<n){
                                ndp[j1][k1] = (ndp[j1][k1]+dp[j][k])%MOD;
                            }else{
                                res = (res+dp[j][k])%MOD;
                            }
                        }
                    }
                }
            }
            dp = ndp;
        }
        return res;
    }
};

int main(){
    Solution s;
    int m=2,n=2,maxMove=2,startRow=0,startColumn = 0;
    int res = s.findPaths(m,n,maxMove,startRow,startColumn);
    cout<<res<<endl;
    return 0;
}