// 802. Find Eventual Safe States
// We start at some node in a directed graph, and every turn, we walk along a directed edge of the graph. If we reach a terminal node (that is, it has no outgoing directed edges), we stop.

// We define a starting node to be safe if we must eventually walk to a terminal node. More specifically, there is a natural number k, so that we must have stopped at a terminal node in less than k steps for any choice of where to walk.

// Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

// The directed graph has n nodes with labels from 0 to n - 1, where n is the length of graph. The graph is given in the following form: graph[i] is a list of labels j such that (i, j) is a directed edge of the graph, going from node i to node j.

 

// Example 1:

// Illustration of graph
// Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
// Output: [2,4,5,6]
// Explanation: The given graph is shown above.
// Example 2:

// Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
// Output: [4]
 

// Constraints:

// n == graph.length
// 1 <= n <= 104
// 0 <= graph[i].length <= n
// graph[i] is sorted in a strictly increasing order.
// The graph may contain self-loops.
// The number of edges in the graph will be in the range [1, 4 * 104].
// 通过次数13,883提交次数26,145

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void print(vector<vector<int>> &Rgraph){
    for(auto t:Rgraph){
        for(int i:t){
            cout<<i<<",";
        }
        cout<<endl;
    }
}

void print(vector<int> &t){
    for(int i:t)cout<<i<<",";
    cout<<endl;
}
class Solution {
public:
    vector<int> color;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        color = vector<int> (n,0);
        vector<int> res;
        for(int i=0;i<n;i++){
            if(safe(i,graph))res.push_back(i);
        }
        return res;
    }
    bool safe(int i,vector<vector<int>>& graph){
        if(color[i]>0)return color[i]==2;
        color[i] = 1;
        for(int t:graph[i]){
            if(!safe(t,graph))return false;
        }
        color[i] = 2;
        return true;
    }
    vector<int> eventualSafeNodes2(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> Rgraph(n);
        vector<int> inDeg(n,0);
        for(int i=0;i<n;i++){
            for(int t:graph[i]){
                Rgraph[t].push_back(i);
            }
            inDeg[i] = graph[i].size();
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDeg[i]==0){
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int t = q.front();
            q.pop();
            for(int i:Rgraph[t]){
                inDeg[i]--;
                if(inDeg[i]==0){
                    q.push(i);
                }
            }
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            if(inDeg[i]==0){
                res.push_back(i);
            }
        }

        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int> res = s.eventualSafeNodes(graph);
    print(res);
    return 0;
}