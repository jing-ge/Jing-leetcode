// 797. All Paths From Source to Target
// Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

// The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

 

// Example 1:


// Input: graph = [[1,2],[3],[3],[]]
// Output: [[0,1,3],[0,2,3]]
// Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
// Example 2:


// Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
// Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
// Example 3:

// Input: graph = [[1],[]]
// Output: [[0,1]]
// Example 4:

// Input: graph = [[1,2,3],[2],[3],[]]
// Output: [[0,1,2,3],[0,2,3],[0,3]]
// Example 5:

// Input: graph = [[1,3],[2],[3],[]]
// Output: [[0,1,2,3],[0,3]]
 

// Constraints:

// n == graph.length
// 2 <= n <= 15
// 0 <= graph[i][j] < n
// graph[i][j] != i (i.e., there will be no self-loops).
// All the elements of graph[i] are unique.
// The input graph is guaranteed to be a DAG.
// 通过次数23,008提交次数29,749

#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>> &data){
    for(auto &t:data){
        for(int i:t){
            cout<<i<<",";
        }
        cout<<endl;
    }
}

class Solution {
public:
    vector<vector<int>> res;
    vector<int> stack;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        stack.push_back(0);
        dfs(graph,0,graph.size()-1);
        return res;
    }
    void dfs(vector<vector<int>> &graph, int x, int n){
        if(x==n){
            res.push_back(stack);
            return ;
        }
        for(int &i:graph[x]){
            stack.push_back(i);
            dfs(graph,i,graph.size()-1);
            stack.pop_back();
        }
        return;
    }
};

int main(){
    Solution s;
    vector<vector<int>> graph = {{1,2},{3},{3},{}};
    vector<vector<int>> res = s.allPathsSourceTarget(graph);
    print(res);
    return 0;
}