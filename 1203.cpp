// 1203. Sort Items by Groups Respecting Dependencies
// There are n items each belonging to zero or one of m groups where group[i] is the group that the i-th item belongs to and it's equal to -1 if the i-th item belongs to no group. The items and the groups are zero indexed. A group can have no item belonging to it.

// Return a sorted list of the items such that:

// The items that belong to the same group are next to each other in the sorted list.
// There are some relations between these items where beforeItems[i] is a list containing all the items that should come before the i-th item in the sorted array (to the left of the i-th item).
// Return any solution if there is more than one solution and return an empty list if there is no solution.

 

// Example 1:



// Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3,6],[],[],[]]
// Output: [6,3,4,1,5,2,0,7]
// Example 2:

// Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3],[],[4],[]]
// Output: []
// Explanation: This is the same as example 1 except that 4 needs to be before 6 in the sorted list.
 

// Constraints:

// 1 <= m <= n <= 3 * 104
// group.length == beforeItems.length == n
// -1 <= group[i] <= m - 1
// 0 <= beforeItems[i].length <= n - 1
// 0 <= beforeItems[i][j] <= n - 1
// i != beforeItems[i][j]
// beforeItems[i] does not contain duplicates elements.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

void print(vector<int>& res){
    for(int &i:res)cout<<i<<",";
    cout<<endl;
}

class TPSort{
public:
    int N;
    vector<int> indegree;
    vector<vector<int>> edges;
    TPSort(int n){
        N = n;
        edges = vector<vector<int>>(n);
        indegree = vector<int>(n,0);
    }
    void addedge(int i, int j){
        if(i!=j&&find(edges[i].begin(),edges[i].end(),j)==edges[i].end()){
            edges[i].push_back(j);
            indegree[j]++;
        }   
    }
    vector<int> sort(){
        cout<<"starting sort....."<<endl;
        queue<int> q;
        vector<int> res;
        for(int i=0;i<N;i++){
            if(indegree[i]==0)q.push(i);
        }

        while(q.size()!=0){
            int t = q.front();q.pop();
            res.push_back(t);
            for(int &i:edges[t]){
                indegree[i]--;
                if(indegree[i]==0)q.push(i);
            }
        }
        if(res.size()!=N)return {};
        return res;
    }
};

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i=0;i<n;i++){
            if(group[i]==-1){
                group[i] = m;
                m++;
            }
        }
        cout<<m<<endl;
        vector<vector<int>> g2i(m);
        TPSort grouptp = TPSort(m);
        for(int i=0;i<n;i++){
            g2i[group[i]].push_back(i);
            int gid = group[i];
            for(int &t:beforeItems[i]){
                int ylgid = group[t];
                cout<<ylgid<<"->"<<gid<<endl;
                grouptp.addedge(ylgid,gid);
            }
        }
        vector<int> groupres = grouptp.sort();
        for(int i=0;i<m;i++){
            cout<<i<<":";
            print(g2i[i]);
        }
        vector<int> res;
        for(int &gid:groupres){
            TPSort tp = TPSort(g2i[gid].size());
            unordered_map<int, int> map;
            for(int i=0;i<g2i[gid].size();i++){
                map[g2i[gid][i]] = i;
            }
            for(int i:g2i[gid]){
                for(int j:beforeItems[i]){
                    if(map.count(i)&&map.count(j))
                        tp.addedge(map[j],map[i]);
                }
            }
            vector<int> r = tp.sort();
            int t = res.size();
            for(int &i:r){
                res.push_back(g2i[gid][i]);
            }
            if(res.size()-t!=map.size())return {};
        }
        return res;
    }
};

int main(){
    // TPSort tp = TPSort(7);
    // tp.addedge(0,2);
    // tp.addedge(0,3);
    // tp.addedge(1,3);
    // tp.addedge(2,4);
    // tp.addedge(3,4);
    // tp.addedge(4,5);
    // tp.addedge(6,1);
    // vector<int>res = tp.sort();
    // print(res);
    Solution s = Solution();
    vector<int> group = {-1,-1,1,0,0,1,0,-1};
    vector<vector<int>> beforeitems = {{},{6},{5},{6},{3,6},{},{},{}};
    vector<int>res = s.sortItems(8,2,group,beforeitems);
    print(res);
    return 0;
}