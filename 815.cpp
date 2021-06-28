// 815. Bus Routes
// You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.

// For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
// You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.

// Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.

 

// Example 1:

// Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
// Output: 2
// Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
// Example 2:

// Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
// Output: -1
 

// Constraints:

// 1 <= routes.length <= 500.
// 1 <= routes[i].length <= 105
// All the values of routes[i] are unique.
// sum(routes[i].length) <= 105
// 0 <= routes[i][j] < 106
// 0 <= source, target < 106
// 通过次数10,943提交次数30,785

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target)return 0;
        int n = routes.size();
        vector<vector<int>> edges(n,vector<int>(n));
        unordered_map<int,vector<int>> rec;
        for(int i=0;i<n;i++){
            for(int t:routes[i]){
                rec[t].push_back(i);
            }
        }

        // build the graph
        for(auto &t:rec){
            for(int &i:t.second){
                for(int &j:t.second){
                    edges[i][j] = edges[j][i] = true;
                }
            }
        }

        vector<int> dis(n,-1);
        queue<int> que;
        for(int &site:rec[source]){
            dis[site] = 1;
            que.push(site);
        }

        while (!que.empty())
        {
            int i = que.front();
            que.pop();
            for(int j=0;j<n;j++){
                if(edges[i][j]&&dis[j]==-1){
                    dis[j] = dis[i]+1;
                    que.push(j);
                }
            }
        }

        int res = INT_MAX;
        for(int &site:rec[target]){
            if(dis[site]!=-1){
                res = min(res,dis[site]);
            }
        }
        return res==INT_MAX?-1:res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> routes = {{1,2,7},{3,6,7}};
    int source = 1, target = 6;
    int res = s.numBusesToDestination(routes,source,target);
    cout<<res<<endl;
    return 0;
}