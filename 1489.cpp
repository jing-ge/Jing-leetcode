// 1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree
// Given a weighted undirected connected graph with n vertices numbered from 0 to n - 1, and an array edges where edges[i] = [ai, bi, weighti] represents a bidirectional and weighted edge between nodes ai and bi. A minimum spanning tree (MST) is a subset of the graph's edges that connects all vertices without cycles and with the minimum possible total edge weight.

// Find all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST). An MST edge whose deletion from the graph would cause the MST weight to increase is called a critical edge. On the other hand, a pseudo-critical edge is that which can appear in some MSTs but not all.

// Note that you can return the indices of the edges in any order.

 

// Example 1:



// Input: n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
// Output: [[0,1],[2,3,4,5]]
// Explanation: The figure above describes the graph.
// The following figure shows all the possible MSTs:

// Notice that the two edges 0 and 1 appear in all MSTs, therefore they are critical edges, so we return them in the first list of the output.
// The edges 2, 3, 4, and 5 are only part of some MSTs, therefore they are considered pseudo-critical edges. We add them to the second list of the output.
// Example 2:



// Input: n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
// Output: [[],[0,1,2,3]]
// Explanation: We can observe that since all 4 edges have equal weight, choosing any 3 edges from the given 4 will yield an MST. Therefore all 4 edges are pseudo-critical.
 

// Constraints:

// 2 <= n <= 100
// 1 <= edges.length <= min(200, n * (n - 1) / 2)
// edges[i].length == 3
// 0 <= ai < bi < n
// 1 <= weighti <= 1000
// All pairs (ai, bi) are distinct.
// 通过次数7,914提交次数11,467

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int>&t){
    for(int i:t){
        cout<<i<<",";
    }
    cout<<endl;
}

class UnionFind{
public:
    vector<int> parent;
    vector<int> size;
    int n;
    UnionFind(int _n):n(_n){
        for(int i=0;i<_n;i++){
            parent.push_back(i);
            size.push_back(1);
        }
    }
    int root(int x){
        return parent[x]==x?x:root(parent[x]);
    }
    int unions(int i,int j){
        i = root(i);
        j = root(j);
        if(i!=j){
            if(size[i]<size[j]){
                parent[i] = j;
                size[j] += size[i];
            }else{
                parent[j] = i;
                size[i]+= size[j];
            }
            n--;
            return true;
        }
        return false;
    }

    bool isConnected(int i,int j){
        return root(i)==root(j);
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for(int i=0;i<m;i++){
            edges[i].push_back(i);
        }
        sort(edges.begin(),edges.end(),[](const auto &a,const auto &b){
            return a[2]<b[2];
        });

        UnionFind uf(n);
        int value = 0;
        for(int i=0;i<m;i++){
            if(uf.unions(edges[i][0],edges[i][1])){
                value+=edges[i][2];
            }
        }
        vector<vector<int>> res(2);
        for(int i=0;i<m;i++){
            //判断关键边
            UnionFind keyuf(n);
            int v = 0;
            for(int j=0;j<m;j++){
                if(i!=j&&keyuf.unions(edges[j][0],edges[j][1])){
                    v+= edges[j][2];
                }
            }
            if(keyuf.n!=1||(keyuf.n==1&&v>value)){
                res[0].push_back(edges[i][3]);
                continue;
            }

            //判断伪关键边
            keyuf = UnionFind(n);
            keyuf.unions(edges[i][0],edges[i][1]);
            v = edges[i][2];
            for(int j=0;j<m;j++){
                if(i!=j&&keyuf.unions(edges[j][0],edges[j][1])){
                    v += edges[j][2];
                }
            }
            if(v==value){
                res[1].push_back(edges[i][3]);
            }
        }
        return res;
    }
};

int main(){
    Solution s = Solution();
    int n = 5;
    vector<vector<int>> edges = {{0,1,1},{1,2,1},{2,3,2},{0,3,2},{0,4,3},{3,4,3},{1,4,6}};
    vector<vector<int>> res = s.findCriticalAndPseudoCriticalEdges(n,edges);
    print(res[0]);
    print(res[1]);
    return 0;
}