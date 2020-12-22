// 面试题 08.02. Robot in a Grid LCCIImagine a robot sitting on the upper left corner of grid with r rows and c columns. The robot can only move in two directions, right and down, but certain cells are "off limits" such that the robot cannot step on them. Design an algorithm to find a path for the robot from the top left to the bottom right.



// "off limits" and empty grid are represented by 1 and 0 respectively.

// Return a valid path, consisting of row number and column number of grids in the path.

// Example 1:

// Input:
// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
// Output: [[0,0],[0,1],[0,2],[1,2],[2,2]]
#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>> &res){
    for(auto i:res){
        for(int j:i){
            cout<<j<<",";
        }
        cout<<endl;
    }
}

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if(n==0)return res;
        int m = obstacleGrid[0].size();
        if(m==0)return res;
        if(obstacleGrid[0][0]==1||obstacleGrid[m-1][n-1]==1)return res;

        vector<vector<int>>dp = obstacleGrid;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1&&j==m-1||dp[i][j]==1)continue;
                if(i==n-1)dp[i][j] = dp[i][j+1];
                else if(j==m-1)dp[i][j] = dp[i+1][j];
                else dp[i][j] = dp[i+1][j]&dp[i][j+1];
            }
        }
        if(dp[0][0]==1)return{};
        dfs(dp,0,0);
        return res;
    }
    void dfs(vector<vector<int>>&dp,int i,int j){
        int n = dp.size(),m = dp[0].size();
        res.push_back({i,j});
        if(i==n-1&&j==m-1)return;
        if(i<n-1&&dp[i+1][j]==0)dfs(dp,i+1,j);
        else if(j<m-1&&dp[i][j+1]==0)dfs(dp,i,j+1);
    }
};

int main(){
    Solution s = Solution();
    vector<vector<int>> data = {{0,0,0},{0,1,0},{0,0,0}};
    vector<vector<int>>  res = s.pathWithObstacles(data);
    print(res);
    return 0;
}