// 1579. Remove Max Number of Edges to Keep Graph Fully Traversable
// Alice and Bob have an undirected graph of n nodes and 3 types of edges:

// Type 1: Can be traversed by Alice only.
// Type 2: Can be traversed by Bob only.
// Type 3: Can by traversed by both Alice and Bob.
// Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.

// Return the maximum number of edges you can remove, or return -1 if it's impossible for the graph to be fully traversed by Alice and Bob.

 

// Example 1:



// Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
// Output: 2
// Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.
// Example 2:



// Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
// Output: 0
// Explanation: Notice that removing any edge will not make the graph fully traversable by Alice and Bob.
// Example 3:



// Input: n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
// Output: -1
// Explanation: In the current graph, Alice cannot reach node 4 from the other nodes. Likewise, Bob cannot reach 1. Therefore it's impossible to make the graph fully traversable.
 

 

// Constraints:

// 1 <= n <= 10^5
// 1 <= edges.length <= min(10^5, 3 * n * (n-1) / 2)
// edges[i].length == 3
// 1 <= edges[i][0] <= 3
// 1 <= edges[i][1] < edges[i][2] <= n
// All tuples (typei, ui, vi) are distinct.
// 通过次数9,781提交次数16,231

#include <iostream>
#include <vector>

using namespace std;

class UnionFind{
public:
    vector<int> parent;
    vector<int> size;
    int n;
    UnionFind(int _n){
        n = _n;
        for(int i=0;i<n;i++){
            parent.push_back(i);
            size.push_back(1);
        }
    }

    int root(int i){
        return i==parent[i]?i:root(parent[i]);
    }

    bool merge(int i,int j){
        i = root(i);
        j = root(j);
        if(i==j)return false;
        if(size[i]<size[j]){
            parent[i] = j;
            size[j]+=size[i];
        }else{
            parent[j] = i;
            size[i] += size[j];
        }
        n--;
        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // 节点编号改为从 0 开始
        for (auto& edge: edges) {
            --edge[1];
            --edge[2];
        }
        UnionFind ufa(n), ufb(n);
        int res = 0;
        //公共边
        for(auto &t:edges){
            if(t[0]==3){
                if(!ufa.merge(t[1],t[2]))res++;
                else{
                    ufb.merge(t[1],t[2]);
                }
            }
        }
        for(auto &t:edges){
            if(t[0]==1){
                if(!ufa.merge(t[1],t[2]))res++;
            }else if(t[0]==2){
                if(!ufb.merge(t[1],t[2]))res++;
            }
        }
        if(ufa.n==1&&ufb.n==1){
            return res;
        }
        return -1;
    }
};

int main(){
    Solution s;
    int n = 4;
    vector<vector<int>> edges = {{3,1,2},{3,2,3},{1,1,3},{1,2,4},{1,1,2},{2,3,4}};
    int res = s.maxNumEdgesToRemove(n,edges);
    cout<<res<<endl;
    return 0;
}