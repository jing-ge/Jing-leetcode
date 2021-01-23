// 1319. Number of Operations to Make Network Connected
// There are n computers numbered from 0 to n-1 connected by ethernet cables connections forming a network where connections[i] = [a, b] represents a connection between computers a and b. Any computer can reach any other computer directly or indirectly through the network.

// Given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected. Return the minimum number of times you need to do this in order to make all the computers connected. If it's not possible, return -1. 

 

// Example 1:



// Input: n = 4, connections = [[0,1],[0,2],[1,2]]
// Output: 1
// Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
// Example 2:



// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
// Output: 2
// Example 3:

// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
// Output: -1
// Explanation: There are not enough cables.
// Example 4:

// Input: n = 5, connections = [[0,1],[0,2],[3,4],[2,3]]
// Output: 0
 

// Constraints:

// 1 <= n <= 10^5
// 1 <= connections.length <= min(n*(n-1)/2, 10^5)
// connections[i].length == 2
// 0 <= connections[i][0], connections[i][1] < n
// connections[i][0] != connections[i][1]
// There are no repeated connections.
// No two computers are connected by more than one cable.

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void print(vector<int>&res){
    for(int &i:res)cout<<i<<",";
    cout<<endl;
}

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
        return i==parent[i]?i:root(parent[i]);
    }
    bool merge(int i,int j){
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)return -1;
        UnionFind uf(n);
        for(auto t:connections){
            uf.merge(t[0],t[1]);
        }
        return uf.n-1;
    }
};

int main(){
    int n = 4;
    vector<vector<int>> connections = {{0,1},{0,2},{1,2}};
    Solution s;
    int res = s.makeConnected(n, connections);
    cout<<res<<endl;
    return 0;
}