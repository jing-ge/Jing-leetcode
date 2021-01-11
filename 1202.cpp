// 1202. Smallest String With Swaps
// You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

// You can swap the characters at any pair of indices in the given pairs any number of times.

// Return the lexicographically smallest string that s can be changed to after using the swaps.

 

// Example 1:

// Input: s = "dcab", pairs = [[0,3],[1,2]]
// Output: "bacd"
// Explaination: 
// Swap s[0] and s[3], s = "bcad"
// Swap s[1] and s[2], s = "bacd"
// Example 2:

// Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
// Output: "abcd"
// Explaination: 
// Swap s[0] and s[3], s = "bcad"
// Swap s[0] and s[2], s = "acbd"
// Swap s[1] and s[2], s = "abcd"
// Example 3:

// Input: s = "cba", pairs = [[0,1],[1,2]]
// Output: "abc"
// Explaination: 
// Swap s[0] and s[1], s = "bca"
// Swap s[1] and s[2], s = "bac"
// Swap s[0] and s[1], s = "abc"
 

// Constraints:

// 1 <= s.length <= 10^5
// 0 <= pairs.length <= 10^5
// 0 <= pairs[i][0], pairs[i][1] < s.length
// s only contains lower case English letters.
// 通过次数5,891提交次数15,440

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

void print(vector<int> & res){
    for(int i:res){
        cout<<i<<",";
    }
    cout<<endl;
}

class UF{
public:
    vector<int> ids;
    vector<int> sizes;
    UF(int n){
        ids = vector<int>(n,0);
        sizes = vector<int>(n,0);
        for(int i=0;i<n;i++){
            ids[i] = i;
        }
    }

    int root(int i){
        while(ids[i]!=i)i = ids[i];
        return i;
    }

    void merge(int i,int j){
        int p = root(i);
        int q = root(j);
        if(sizes[p]<sizes[q]){
            ids[p] = q;
            sizes[q]+=sizes[p];
        }
        else
        {
            ids[q] = p;
            sizes[p] +=  q;
        }
        
    }
};


class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        UF uf = UF(s.size());
        for(auto &t:pairs){
            uf.merge(t[0],t[1]);
        }
        unordered_map<int,vector<int>> g2ids;
        unordered_map<int,vector<char>> g2chars;
        string res = s;
        for(int i=0;i<uf.ids.size();i++){
            int gid = uf.root(uf.ids[i]);
            g2ids[gid].push_back(i);
            g2chars[gid].push_back(s[i]);
        }
        // for(auto t:g2ids){
        //     cout<<t.first<<":";
        //     print(t.second);
        // }
        for(auto &t:g2chars){
            sort(t.second.begin(),t.second.end());
        }
        for(auto &t:g2ids){
            int idx = t.first;
            for(int i=0;i<g2ids[idx].size();i++){
                res[g2ids[idx][i]] = g2chars[idx][i];
            }
        }
        return res;
    }
};

int main(){
    Solution s = Solution();
    string str = "cba";
    vector<vector<int>> pairs = {{0,1},{1,2}};
    string res = s.smallestStringWithSwaps(str, pairs);
    cout<<res<<endl;
    return 0;
}