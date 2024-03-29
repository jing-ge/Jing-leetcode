// 743. Network Delay Time
// You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

// We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 

// Example 1:


// Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
// Output: 2
// Example 2:

// Input: times = [[1,2,1]], n = 2, k = 1
// Output: 1
// Example 3:

// Input: times = [[1,2,1]], n = 2, k = 2
// Output: -1
 

// Constraints:

// 1 <= k <= n <= 100
// 1 <= times.length <= 6000
// times[i].length == 3
// 1 <= ui, vi <= n
// ui != vi
// 0 <= wi <= 100
// All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
// 通过次数33,100提交次数67,272

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int inf = INT32_MAX/2;
        vector<vector<int>> g(n,vector<int>(n,inf));
        for(auto &t:times){
            g[t[0]-1][t[1]-1] = t[2];
        }
        vector<int> dist(n,inf);
        dist[k-1]=0;
        vector<int> used(n);
        for(int i=0;i<n;i++){
            int x = -1;
            for(int y = 0;y<n;y++){
                if(!used[y]&&(x==-1||dist[y]<dist[x])){
                    x = y;
                }
            }
            used[x] = 1;
            for(int y=0;y<n;y++){
                dist[y] = min(dist[y],dist[x]+g[x][y]);
            }
        }
        int res = *max_element(dist.begin(),dist.end());
        return res==inf?-1:res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n=4,k=2;
    int res = s.networkDelayTime(times,n,k);
    cout<<res<<endl;
    return 0;
}