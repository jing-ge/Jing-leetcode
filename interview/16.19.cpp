// 面试题 16.19. Pond Sizes LCCI
// You have an integer matrix representing a plot of land, where the value at that loca­tion represents the height above sea level. A value of zero indicates water. A pond is a region of water connected vertically, horizontally, or diagonally. The size of the pond is the total number of connected water cells. Write a method to compute the sizes of all ponds in the matrix.

// Example:

// Input: 
// [
//   [0,2,1,0],
//   [0,1,0,1],
//   [1,1,0,1],
//   [0,1,0,1]
// ]
// Output:  [1,2,4]
// Note:

// 0 < len(land) <= 1000
// 0 < len(land[i]) <= 1000
// 通过次数12,227提交次数20,288

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int size = 0;
    int m = 0;
    int n = 0;
    vector<vector<int>>visited;
    vector<int> pondSizes(vector<vector<int>>& land) {
        m = land.size();n = land[0].size();
        vector<int>res;
        visited = vector<vector<int>>(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                size = 0;
                dfs(land,i,j);
                if(size!=0)res.push_back(size);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
    void dfs(vector<vector<int>>& lands,int i,int j){
        if(i<0||i>=m||j<0||j>=n||lands[i][j]!=0||visited[i][j]==1)return;
        size++;
        visited[i][j]=1;
        dfs(lands,i-1,j);
        dfs(lands,i+1,j);
        dfs(lands,i,j-1);
        dfs(lands,i,j+1);
        dfs(lands,i-1,j-1);
        dfs(lands,i-1,j+1);
        dfs(lands,i+1,j-1);
        dfs(lands,i+1,j+1);
    }
};

int main(){
    Solution s = Solution();
    vector<vector<int>> lands = {
                                    {0,2,1,0},
                                    {0,1,0,1},
                                    {1,1,0,1},
                                    {0,1,0,1}
                                };
    vector<int>res = s.pondSizes(lands);
    for(int i:res){
        cout<<i<<",";
    }
    cout<<endl;
    return 0;
}