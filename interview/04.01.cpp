// 面试题 04.01. Route Between Nodes LCCI
// Given a directed graph, design an algorithm to find out whether there is a route between two nodes.

// Example1:

//  Input: n = 3, graph = [[0, 1], [0, 2], [1, 2], [1, 2]], start = 0, target = 2
//  Output: true
// Example2:

//  Input: n = 5, graph = [[0, 1], [0, 2], [0, 4], [0, 4], [0, 1], [1, 3], [1, 4], [1, 3], [2, 3], [3, 4]], start = 0, target = 4
//  Output true
// Note:

// 0 <= n <= 100000
// All node numbers are within the range [0, n].
// There might be self cycles and duplicated edges.


#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<bool>visited;
    vector<unordered_set<int>>adj;
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        adj = vector<unordered_set<int>>(n);
        visited = vector<bool>(n,false);
        for(auto& link:graph){
            if (link[0]!=link[1])
            {
                adj[link[0]].insert(link[1]);
            }
        }
        return bfs(start,target);
    }
    bool dfs(int start,int target){
        if(start==target)return true;
        visited[start] = true;
        for(int i:adj[start]){
            if(visited[i])continue;
            if(bfs(i,target))
                return true;
        }
        return false;
    }
    bool bfs(int start,int target){
        if(start==target)return true;
        queue<int>q;
        q.push(start);
        visited[start] = true;
        while (!q.empty())
        {
            int t = q.front();q.pop();
            if(t==target)return true;
            for(int i:adj[t]){
                if(visited[i])continue;
                q.push(i);
                visited[i] = true;
            }
        }
        return false;
    }
};

int main(){
    int n=3;
    vector<vector<int>>graph = {{0, 1}, {0, 2}, {1, 2}, {1, 2}};
    int start = 0;
    int target = 2;
    Solution s = Solution();
    bool res = s.findWhetherExistsPath(n,graph,start,target);
    cout<<res<<endl;
    return 0;
}