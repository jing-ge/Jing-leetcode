// 131. Palindrome Partitioning
// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

// A palindrome string is a string that reads the same backward as forward.

 

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]
 

// Constraints:

// 1 <= s.length <= 16
// s contains only lowercase English letters.
// 通过次数75,101提交次数104,733

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<string>> res;
    vector<string> temp;
    void dfs(string &s,int i){
        if(i==s.size()){
            res.push_back(temp);
            return;
        }
        for(int j=i;j<s.size();j++){
            if(dp[i][j]){
                temp.push_back(s.substr(i,j-i+1));
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
    string str = "aab";
    Solution s;
    vector<vector<string>> res = s.partition(str);
    for(auto t:res){
        for(auto tt:t){
            cout<<tt<<",";
        }
        cout<<endl;
    }
    return 0;
}
