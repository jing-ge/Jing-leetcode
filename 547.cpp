// 547. Number of Provinces
// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.

 

// Example 1:


// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Output: 2
// Example 2:


// Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
// Output: 3
 

// Constraints:

// 1 <= n <= 200
// n == isConnected.length
// n == isConnected[i].length
// isConnected[i][j] is 1 or 0.
// isConnected[i][i] == 1
// isConnected[i][j] == isConnected[j][i]
// 通过次数85,385提交次数143,196

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void print(vector<vector<int>>& res){
    for(auto t:res){
        for(int i:t){
            cout<<i<<",";
        }
        cout<<endl;
    }
}

class Solution {
public:
vector<vector<int>> visited;
int groupid;
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        cout<<n<<endl;
        visited = vector<vector<int>>(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            if(visited[i][i]==0){
                dfs(isConnected,i);
                // print(visited);
                // cout<<"----------"<<endl;
                groupid++;
            }
        }
        return groupid;
    }
    void dfs(vector<vector<int>>& isConnected,int i){
        for(int j=0;j<isConnected.size();j++){
            if(isConnected[i][j]==1&&visited[i][j] == 0){
                visited[i][j] = 1;
                dfs(isConnected,j);
            }   
        }
    }
};

int main(){
    Solution s = Solution();
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,1,1,1},{0,0,1}};
    int res = s.findCircleNum(isConnected);
    cout<<res<<endl;
    return 0;
}