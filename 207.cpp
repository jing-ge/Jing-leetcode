// 207. Course Schedule
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
//              To take course 1 you should have finished course 0. So it is possible.
// Example 2:

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
//              To take course 1 you should have finished course 0, and to take course 0 you should
//              also have finished course 1. So it is impossible.
 

// Constraints:

// The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
// You may assume that there are no duplicate edges in the input prerequisites.
// 1 <= numCourses <= 10^5
// 通过次数88,763提交次数162,329

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;


class TPSort{
public:
    int N;
    vector<int> indegree;
    vector<unordered_set<int>> edgeset;
    TPSort(int n){
        N = n;
        indegree = vector<int>(n,0);
        edgeset = vector<unordered_set<int>>(n);
    }
    void addedge(int i, int j){
        if(i!=j&&edgeset[i].count(j)==0){
            edgeset[i].insert(j);
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
            for(auto it=edgeset[t].begin();it!=edgeset[t].end();it++){
                int i = *it;
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        TPSort tp = TPSort(numCourses);
        for(auto &t:prerequisites){
            tp.addedge(t[1],t[0]);
        }
        return tp.sort().size();
    }
};

int main(){
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0}};
    Solution s = Solution();
    bool res = s.canFinish(numCourses,prerequisites);
    cout<<res<<endl;
    return 0;
}