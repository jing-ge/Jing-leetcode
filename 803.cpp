// 803. Bricks Falling When Hit
// You are given an m x n binary grid, where each 1 represents a brick and 0 represents an empty space. A brick is stable if:

// It is directly connected to the top of the grid, or
// At least one other brick in its four adjacent cells is stable.
// You are also given an array hits, which is a sequence of erasures we want to apply. Each time we want to erase the brick at the location hits[i] = (rowi, coli). The brick on that location (if it exists) will disappear. Some other bricks may no longer be stable because of that erasure and will fall. Once a brick falls, it is immediately erased from the grid (i.e., it does not land on other stable bricks).

// Return an array result, where each result[i] is the number of bricks that will fall after the ith erasure is applied.

// Note that an erasure may refer to a location with no brick, and if it does, no bricks drop.

 

// Example 1:

// Input: grid = [[1,0,0,0],[1,1,1,0]], hits = [[1,0]]
// Output: [2]
// Explanation: Starting with the grid:
// [[1,0,0,0],
//  [1,1,1,0]]
// We erase the underlined brick at (1,0), resulting in the grid:
// [[1,0,0,0],
//  [0,1,1,0]]
// The two underlined bricks are no longer stable as they are no longer connected to the top nor adjacent to another stable brick, so they will fall. The resulting grid is:
// [[1,0,0,0],
//  [0,0,0,0]]
// Hence the result is [2].
// Example 2:

// Input: grid = [[1,0,0,0],[1,1,0,0]], hits = [[1,1],[1,0]]
// Output: [0,0]
// Explanation: Starting with the grid:
// [[1,0,0,0],
//  [1,1,0,0]]
// We erase the underlined brick at (1,1), resulting in the grid:
// [[1,0,0,0],
//  [1,0,0,0]]
// All remaining bricks are still stable, so no bricks fall. The grid remains the same:
// [[1,0,0,0],
//  [1,0,0,0]]
// Next, we erase the underlined brick at (1,0), resulting in the grid:
// [[1,0,0,0],
//  [0,0,0,0]]
// Once again, all remaining bricks are still stable, so no bricks fall.
// Hence the result is [0,0].
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 200
// grid[i][j] is 0 or 1.
// 1 <= hits.length <= 4 * 104
// hits[i].length == 2
// 0 <= xi <= m - 1
// 0 <= yi <= n - 1
// All (xi, yi) are unique.
// 通过次数4,864提交次数11,256
#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& res){
    for(int &i:res)cout<<i<<",";
    cout<<endl;
}


class UnionFind{
public:
    vector<int> ids;
    vector<int> sizes;
    UnionFind(int n){
        for(int i=0;i<n;i++){
            ids.push_back(i);
        }
        sizes = vector<int>(n,1);
    }
    int root(int i){
        while(i!=ids[i])i = ids[i];
        return i;
    }
    void unions(int i,int j){
        int p = root(i);
        int q = root(j);
        // cout<<"union:"<<i<<","<<j<<",root:"<<p<<","<<q<<endl;
        if(p!=q){
            if(sizes[p]<sizes[q]){
                ids[p] = q;
                sizes[q]+=sizes[p];
            }else{
                ids[q] = p;
                sizes[p]+=sizes[q];
            }
        }
    }
};

class Solution {
public:
    int m=0,n=0;
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        vector<bool> copy(hits.size(),0);
        m = grid.size();n = grid[0].size();
        UnionFind uf = UnionFind(m*n+1);
        //碎砖
        for(int i=0;i<hits.size();i++){
            if(grid[hits[i][0]][hits[i][1]])copy[i]=1;
            grid[hits[i][0]][hits[i][1]] = 0;
        }
        //建图
        for(int j=0;j<n;j++){
            if(grid[0][j])
            uf.unions(0,getidx(0,j));
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j+1<n&&grid[i][j]&&grid[i][j+1])uf.unions(getidx(i,j),getidx(i,j+1));
                if(i+1<m&&grid[i][j]&&grid[i+1][j])uf.unions(getidx(i,j),getidx(i+1,j));
            }
        }
        // cout<<uf.sizes[0]<<endl;
        vector<int>res(hits.size(),0);
        //补回
        int x = 0,y=0,tmp = 0;
        for(int i=hits.size()-1;i>=0;i--){
            if(copy[i]){
                x = hits[i][0];y = hits[i][1];
                tmp = uf.sizes[uf.root(0)];
                grid[x][y] = 1;
                if(x+1<m&&grid[x+1][y])uf.unions(getidx(x+1,y),getidx(x,y));
                if(x-1>=0&&grid[x-1][y])uf.unions(getidx(x-1,y),getidx(x,y));
                if(y+1<n&&grid[x][y+1])uf.unions(getidx(x,y+1),getidx(x,y));
                if(y-1>=0&&grid[x][y-1])uf.unions(getidx(x,y-1),getidx(x,y));
                if(x==0)uf.unions(0,getidx(x,y));
                res[i] = max(0,uf.sizes[uf.root(0)]-tmp-1);
                // print(uf.ids);
                // print(uf.sizes);
            }
        }
        return res;
    }
    constexpr int getidx(int i,int j){
        return i*n+j+1;
    }
};

int main(){
    vector<vector<int>> grid = {{1,0,1},{1,1,1}};
    vector<vector<int>> hits = {{0,0},{0,2},{1,1}};
    Solution s = Solution();
    vector<int> res = s.hitBricks(grid, hits);
    print(res);
    return 0;
}