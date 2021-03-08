// 132. Palindrome Partitioning II
// Given a string s, partition s such that every substring of the partition is a palindrome.

// Return the minimum cuts needed for a palindrome partitioning of s.

 

// Example 1:

// Input: s = "aab"
// Output: 1
// Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
// Example 2:

// Input: s = "a"
// Output: 0
// Example 3:

// Input: s = "ab"
// Output: 1
 

// Constraints:

// 1 <= s.length <= 2000
// s consists of lower-case English letters only.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int r = INT32_MAX;
    //按照上一道题的做法超时了
    int minCut1(string s) {
        vector<vector<string>> res = partition(s);
        return r-1;
    }

    int minCut(string s){
        int n = s.size();
        vector<vector<int>> g(n,vector<int>(n,true));
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                g[i][j] = (s[i]==s[j])&&g[i+1][j-1];
            }
        }
        vector<int> f(n,INT32_MAX);
        for(int i=0;i<n;i++){
            if(g[0][i]){
                f[i] = 0;
            }else{
                for(int j=0;j<i;j++){
                    if(g[j+1][i])
                    f[i] = min(f[i],f[j]+1);
                }
            }
        }
        return f[n-1];
    }

    vector<vector<int>> dp;
    vector<vector<string>> res;
    vector<string> temp;
    void dfs(string &s,int i){
        if(i==s.size()){
            res.push_back(temp);
            r = min(r,(int)temp.size());
            return;
        }
        for(int j=i;j<s.size();j++){
            if(dp[i][j]){
                temp.push_back(s.substr(i,j-i+1));
                if(temp.size()>r)return;
                dfs(s,j+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        dp = vector<vector<int>> (n,vector<int>(n,true));

        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                dp[i][j] = s[i]==s[j]&&dp[i+1][j-1];
            }
        }

        dfs(s,0);
        return res;
    }
};

int main(){
    Solution s;
    string str = "ab";
    int res = s.minCut(str);
    cout<<res<<endl;
    return 0;
}