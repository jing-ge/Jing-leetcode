// 399. Evaluate Division
// You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

// You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

// Return the answers to all queries. If a single answer cannot be determined, return -1.0.

// Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

 

// Example 1:

// Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
// Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
// Explanation: 
// Given: a / b = 2.0, b / c = 3.0
// queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
// return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
// Example 2:

// Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
// Output: [3.75000,0.40000,5.00000,0.20000]
// Example 3:

// Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
// Output: [0.50000,2.00000,-1.00000,-1.00000]
 

// Constraints:

// 1 <= equations.length <= 20
// equations[i].length == 2
// 1 <= Ai.length, Bi.length <= 5
// values.length == equations.length
// 0.0 < values[i] <= 20.0
// 1 <= queries.length <= 20
// queries[i].length == 2
// 1 <= Cj.length, Dj.length <= 5
// Ai, Bi, Cj, Dj consist of lower case English letters and digits.
// 通过次数15,792提交次数28,181
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <set>

using namespace std;

void print(vector<double>&res){
    for(double &d:res){
        cout<<d<<",";
    }
    cout<<endl;
}


void print(vector<string>&res){
    for(string &d:res){
        cout<<d<<",";
    }
    cout<<endl;
}
class Solution {
public:
    unordered_map<string,vector<string>> g;
    unordered_map<string,vector<double>> v;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i=0;i<equations.size();i++){
            g[equations[i][0]].push_back(equations[i][1]);
            g[equations[i][1]].push_back(equations[i][0]);
            v[equations[i][0]].push_back(values[i]);
            v[equations[i][1]].push_back(1/values[i]);
        }


        // for(auto t:g){
        //     cout<<t.first<<":";
        //     print(t.second);
        // }
        // for(auto t:v){
        //     cout<<t.first<<":";
        //     print(t.second);
        // }
        // cout<<"--------------"<<endl;
        return bfs(queries);
    }
    vector<double> bfs(vector<vector<string>>& queries){
        vector<double> res;
        int n = queries.size();
        for(int i=0;i<n;i++){
            string src = queries[i][0],des = queries[i][1];
            double cur = 1.0;
            queue<string> q;
            set<string> s;
            //bfs
            q.push(src);
            s.insert(src);
            unordered_map<string,double> data;
            data[src] = 1;
            while(!q.empty()){
                string tmp = q.front();
                q.pop();
                for(int i=0;i<g[tmp].size();i++){
                    if(s.count(g[tmp][i]))continue;
                    if(data.find(g[tmp][i])==data.end()){
                        data[g[tmp][i]] = data[tmp]*v[tmp][i];
                    }else{
                        data[g[tmp][i]] *= v[tmp][i];
                    }
                    if(g[tmp][i]==des)goto breakloop;
                    q.push(g[tmp][i]);
                    s.insert(g[tmp][i]);
                }
            }
breakloop:
            if(g[des].size()==0){
                res.push_back(-1);
            }else{
                if(data.find(des)==data.end()){
                    res.push_back(-1);
                }else{
                    res.push_back(data[des]);   
                }
            }
        }
        return res;
    }
};
 
int main(){
    Solution s = Solution();
    vector<vector<string>> equations = {{"a","b"} ,{"b","c"}};
    vector<double> values = {2.0,3.0};
    vector<vector<string>> queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    vector<double> res = s.calcEquation(equations,values,queries);
    print(res);
    return 0;
}