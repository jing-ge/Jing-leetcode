// 1743. Restore the Array From Adjacent Pairs
// There is an integer array nums that consists of n unique elements, but you have forgotten it. However, you do remember every pair of adjacent elements in nums.

// You are given a 2D integer array adjacentPairs of size n - 1 where each adjacentPairs[i] = [ui, vi] indicates that the elements ui and vi are adjacent in nums.

// It is guaranteed that every adjacent pair of elements nums[i] and nums[i+1] will exist in adjacentPairs, either as [nums[i], nums[i+1]] or [nums[i+1], nums[i]]. The pairs can appear in any order.

// Return the original array nums. If there are multiple solutions, return any of them.

 

// Example 1:

// Input: adjacentPairs = [[2,1],[3,4],[3,2]]
// Output: [1,2,3,4]
// Explanation: This array has all its adjacent pairs in adjacentPairs.
// Notice that adjacentPairs[i] may not be in left-to-right order.
// Example 2:

// Input: adjacentPairs = [[4,-2],[1,4],[-3,1]]
// Output: [-2,4,1,-3]
// Explanation: There can be negative numbers.
// Another solution is [-3,1,4,-2], which would also be accepted.
// Example 3:

// Input: adjacentPairs = [[100000,-100000]]
// Output: [100000,-100000]
 

// Constraints:

// nums.length == n
// adjacentPairs.length == n - 1
// adjacentPairs[i].length == 2
// 2 <= n <= 105
// -105 <= nums[i], ui, vi <= 105
// There exists some nums that has adjacentPairs as its pairs.
// 通过次数14,618提交次数21,483

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> mp;
        for(auto &t:adjacentPairs){
            mp[t[0]].push_back(t[1]);
            mp[t[1]].push_back(t[0]);
        }
        int n = adjacentPairs.size()+1;
        vector<int> res(n);
        for(auto &t:mp){
            if(t.second.size()==1){
                res[0] = t.first;
                break;
            }
        }
        res[1] = mp[res[0]][0];
        for(int i=2;i<n;i++){
            res[i] = res[i-2]==mp[res[i-1]][0]?mp[res[i-1]][1]:mp[res[i-1]][0];
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> adj = {{2,1},{3,4},{3,2}};
    vector<int> res = s.restoreArray(adj);
    for(int i:res){
        cout<<i<<",";
    }
    cout<<endl;
    return 0;
}