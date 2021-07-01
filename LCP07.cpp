// LCP 07. 传递信息
// 小朋友 A 在和 ta 的小伙伴们玩传信息游戏，游戏规则如下：

// 有 n 名玩家，所有玩家编号分别为 0 ～ n-1，其中小朋友 A 的编号为 0
// 每个玩家都有固定的若干个可传信息的其他玩家（也可能没有）。传信息的关系是单向的（比如 A 可以向 B 传信息，但 B 不能向 A 传信息）。
// 每轮信息必须需要传递给另一个人，且信息可重复经过同一个人
// 给定总玩家数 n，以及按 [玩家编号,对应可传递玩家编号] 关系组成的二维数组 relation。返回信息从小 A (编号 0 ) 经过 k 轮传递到编号为 n-1 的小伙伴处的方案数；若不能到达，返回 0。

// 示例 1：

// 输入：n = 5, relation = [[0,2],[2,1],[3,4],[2,3],[1,4],[2,0],[0,4]], k = 3

// 输出：3

// 解释：信息从小 A 编号 0 处开始，经 3 轮传递，到达编号 4。共有 3 种方案，分别是 0->2->0->4， 0->2->1->4， 0->2->3->4。

// 示例 2：

// 输入：n = 3, relation = [[0,2],[2,1]], k = 2

// 输出：0

// 解释：信息不能从小 A 处经过 2 轮传递到编号 2

// 限制：

// 2 <= n <= 10
// 1 <= k <= 5
// 1 <= relation.length <= 90, 且 relation[i].length == 2
// 0 <= relation[i][0],relation[i][1] < n 且 relation[i][0] != relation[i][1]
// 通过次数28,581提交次数37,484

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

void print(vector<vector<int>> &adj){
    for(auto t:adj){
        for(int i:t){
            cout<<i<<",";
        }
        cout<<endl;
    }
}

class Solution {
public:
    int res,K,N;
    int numWays_dfs(int n, vector<vector<int>>& relation, int k) {
        K = k;
        N = n;
        vector<vector<int>> adj(n);
        for(auto &t:relation){
            adj[t[0]].push_back(t[1]);
        }
        res = 0;
        dfs(adj,0,0);
        return res;
    }
    void dfs(vector<vector<int>>& adj,int idx,int step){
        if(step==K){
            if(idx==N-1)
                res++;
            return;
        }
        for(int t:adj[idx]){
            dfs(adj,t,step+1);
        }
    }
    int numWays_bfs(int n, vector<vector<int>>& relation, int k) {
        vector<vector<int>> adj(n);
        for(auto &t:relation){
            adj[t[0]].push_back(t[1]);
        }
        queue<int> q;
        q.push(0);
        int step = 0;
        while (step<k)
        {
            int size = q.size();
            for(int i=0;i<size;i++){
                int t = q.front();
                q.pop();
                for(int i:adj[t]){
                    q.push(i);
                }
            }
            step++;
        }
        int res = 0;
        while (!q.empty())
        {
            int t = q.front();
            q.pop();
            if(t==n-1)res++;
        }
        return res;
    }
    int numWays_dp(int n, vector<vector<int>>& relation, int k) {
        vector<int> dp(n);
        dp[0] = 1;
        for(int i=0;i<k;i++){
            vector<int> temp(n);
            for(auto&rel: relation){
                temp[rel[1]]+=dp[rel[0]];
            }
            dp = temp;
        }
        return dp[n-1];
    }
    int numWays(int n, vector<vector<int>>& relation, int k) {
        vector<vector<int>> adj(n,vector<int>(n)),res(n,vector<int>(n));
        for(int i=0;i<n;i++)res[i][i] = 1;
        for(auto &t:relation){
            adj[t[0]][t[1]] = 1;
        }
        for(int i=1;i<=k;i++){
            res = matrix_multiply(res,adj);
        }
        
        return res[0][n-1];
    }
    vector<vector<int>> matrix_multiply(vector<vector<int>>& A,vector<vector<int>>& B){
        vector<vector<int>>res;
        if (A[0].size()!=B.size())
        {
            throw "the cols of A must equal as the rows of B" ;
        }
        res = vector<vector<int>> (A.size(),vector<int>(B[0].size()));
        for(int i=0;i<A.size();i++){
            for(int j=0;j<B[0].size();j++){
                int t = 0;
                for(int k=0;k<B.size();k++){
                    t += A[i][k]*B[k][j];
                }
                res[i][j] = t;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 5, k = 3;
    vector<vector<int>> relation = {{0,2},{2,1},{3,4},{2,3},{1,4},{2,0},{0,4}};
    int res = s.numWays(n,relation,k);
    cout<<res<<endl;
    return 0;
}