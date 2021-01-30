// 778. Swim in Rising Water
// On an N x N grid, each square grid[i][j] represents the elevation at that point (i,j).

// Now rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distance in zero time. Of course, you must stay within the boundaries of the grid during your swim.

// You start at the top left square (0, 0). What is the least time until you can reach the bottom right square (N-1, N-1)?

// Example 1:

// Input: [[0,2],[1,3]]
// Output: 3
// Explanation:
// At time 0, you are in grid location (0, 0).
// You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.

// You cannot reach point (1, 1) until time 3.
// When the depth of water is 3, we can swim anywhere inside the grid.
// Example 2:

// Input: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
// Output: 16
// Explanation:
//  0  1  2  3  4
// 24 23 22 21  5
// 12 13 14 15 16
// 11 17 18 19 20
// 10  9  8  7  6

// The final route is marked in bold.
// We need to wait until time 16 so that (0, 0) and (4, 4) are connected.

#include <iostream>
#include <vector>
#include <algorithm>

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
        while(parent[i]!=i){
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;
    }
    bool merge(int i, int j){
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
    //每次模拟时间超时
    int swimInWater1(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        
        UnionFind uf(m*n);
        int t = 0;
        while(true){
            for(int i=1;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]<=t&&grid[i-1][j]<=t){
                        uf.merge(i*n+j,(i-1)*n+j);
                    }
                    if(grid[j][i]<=t&&grid[j][i-1]<=t){
                        uf.merge(j*n+i,j*n+i-1);
                    }
                }
            }
            if(uf.root(0)==uf.root(m*n-1))break;
            t++;
        }
        return t;
    }
    //先排序后合并
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        
        UnionFind uf(m*n);
        vector<vector<int>> edges;
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                edges.push_back({i*n+j,(i-1)*n+j,max(grid[i][j],grid[i-1][j])});
                edges.push_back({j*n+i,j*n+i-1,max(grid[j][i],grid[j][i-1])});
            }
        }
        sort(edges.begin(),edges.end(),[](const vector<int>&a,const vector<int>&b)->bool{
            return a[2]<b[2];
        });
        int res = 0;
        for(auto &t:edges){
            uf.merge(t[0],t[1]);
            res = max(res,t[2]);
            if(uf.root(0)==uf.root(m*n-1))break;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid =  {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
    int res = s.swimInWater(grid);
    cout<<res<<endl;
    return 0;
}