// 1631. Path With Minimum Effort
// You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

// A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

// Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

// Example 1:



// Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
// Output: 2
// Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
// This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
// Example 2:



// Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
// Output: 1
// Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
// Example 3:


// Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
// Output: 0
// Explanation: This route does not require any effort.
 

// Constraints:

// rows == heights.length
// columns == heights[i].length
// 1 <= rows, columns <= 100
// 1 <= heights[i][j] <= 106
// 通过次数13,500提交次数28,960

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
        while (parent[i]!=i)
        {
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
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(),n = heights[0].size();
        vector<vector<int>> edges;
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                edges.push_back({i*n+j,(i-1)*n+j,abs(heights[i][j]-heights[i-1][j])});
            }
        }
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                edges.push_back({i*n+j,i*n+j-1,abs(heights[i][j]-heights[i][j-1])});
            }
        }
        sort(edges.begin(),edges.end(),[](const vector<int>&a,const vector<int>&b)->bool{
            return a[2]<b[2];
        });
        UnionFind uf(m*n);
        int res = 0;
        for(auto t:edges){
            if(uf.merge(t[0],t[1]))
                res = max(res,t[2]);
            if(uf.root(0)==uf.root(m*n-1))break;
        }
        return res;
    }
};

int main(){
    vector<vector<int>> heights = {{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}};
    Solution s;
    int res = s.minimumEffortPath(heights);
    cout<<res<<endl;
    return 0;
}