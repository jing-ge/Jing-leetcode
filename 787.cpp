// 787. Cheapest Flights Within K Stops
// There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

 

// Example 1:


// Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
// Output: 200
// Explanation: The graph is shown.
// The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
// Example 2:


// Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
// Output: 500
// Explanation: The graph is shown.
// The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
 

// Constraints:

// 1 <= n <= 100
// 0 <= flights.length <= (n * (n - 1) / 2)
// flights[i].length == 3
// 0 <= fromi, toi < n
// fromi != toi
// 1 <= pricei <= 104
// There will not be any multiple flights between two cities.
// 0 <= src, dst, k < n
// src != dst
// 通过次数25,918提交次数70,177
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(vector<vector<int>>& data){
    for(auto&t:data){
        for(int i:t){
            cout<<i<<",";
        }
        cout<<endl;
    }
}

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int INF = 10000 * 101 + 1;
        vector<vector<int>> dp(k+2,vector<int>(n,INF));
        dp[0][src] = 0;
        // print(dp);

        for(int t=1;t<=k+1;t++){
            for(auto&f:flights){
                int s = f[0],d = f[1],cost = f[2];
                dp[t][d] = min(dp[t][d],dp[t-1][s]+cost);
            }
        }
        // print(dp);
        int res = INF;
        for(int t=1;t<=k+1;t++){
            res = min(res,dp[t][dst]);
            cout<<dp[t][dst]<<endl;
        }
        return res==INF?-1:res;
    }
};

int main(){
    Solution s;
    int n = 3;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
    int src = 0,dst = 2,k = 1;
    int res = s.findCheapestPrice(n,flights,src, dst,k);
    cout<<res<<endl;
    return 0;
}