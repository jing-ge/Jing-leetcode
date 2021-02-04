// 332. Reconstruct Itinerary
// Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

// Note:

// If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
// All airports are represented by three capital letters (IATA code).
// You may assume all tickets form at least one valid itinerary.
// One must use all the tickets once and only once.
// Example 1:

// Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
// Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
// Example 2:

// Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
// Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
// Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
//              But it is larger in lexical order.
// 通过次数28,590提交次数64,859

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>> map;
    vector<string> res;
    void dfs(const string &s){
        while(map.count(s)&&map[s].size()>0){
            string tmp = map[s].top();
            map[s].pop();
            dfs(tmp);
        }
        res.push_back(s);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto &t:tickets){
            map[t[0]].push(t[1]);
        }
        dfs("JFK");
        reverse(res.begin(),res.end());
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<string>> tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    vector<string> res = s.findItinerary(tickets);
    for(string t:res){
        cout<<t<<",";
    }
    cout<<endl;
    return 0;
}