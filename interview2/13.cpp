// 剑指 Offer 13. 机器人的运动范围
// 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

 

// 示例 1：

// 输入：m = 2, n = 3, k = 1
// 输出：3
// 示例 2：

// 输入：m = 3, n = 1, k = 0
// 输出：1
// 提示：

// 1 <= n,m <= 100
// 0 <= k <= 20
// 通过次数146,342提交次数279,535

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int res,K,M,N;
    vector<vector<bool>> visited;
    int getsum(int t){
        int res = 0;
        while(t){
            res+=t%10;
            t = t/10;
        }
        return res;
    }
    int movingCount(int m, int n, int k) {
        res = 0;
        K = k;
        M = m;
        N = n;
        visited = vector<vector<bool>> (m,vector<bool>(n,false));
        dfs(0,0);
        return res;
    }
    void dfs(int i,int j){
        if(i>=M||i<0||j>=N||j<0||(getsum(i)+getsum(j))>K||visited[i][j])return;
        visited[i][j]=true;
        res++;
        dfs(i-1,j);
        dfs(i+1,j);
        dfs(i,j-1);
        dfs(i,j+1);
        return ;
    }
};

int main(){
    Solution s;
    int m=3,n=1,k=0;
    // int res = s.movingCount(m,n,k);
    int res = s.getsum(41);
    cout<<res<<endl;
    return 0;
}