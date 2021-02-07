// 22. Generate Parentheses
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]
 

// Constraints:

// 1 <= n <= 8
// 通过次数224,887提交次数292,895

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string t;
        dfs(res,n,n,t);
        return res;
    }
    void dfs(vector<string>& res,int left,int right,string path){
        if(left==0&&right==0){
            res.push_back(path);
        }
        if(left>0) dfs(res,left-1,right,path+"(");
        if(left<right) dfs(res,left,right-1,path+")");
    }
};

int main(){
    int n = 3;
    Solution s;
    vector<string> res = s.generateParenthesis(n);
    for(string t:res)cout<<t<<",";
    cout<<endl;
    return 0;
}