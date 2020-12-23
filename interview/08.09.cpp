// 面试题 08.09. Bracket LCCIImplement an algorithm to print all valid (e.g., properly opened and closed) combinations of n pairs of parentheses.

// Note: The result set should not contain duplicated subsets.

// For example, given n = 3, the result should be:

// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(vector<string>&res){
    for(string s :res){
        cout<<s<<endl;
    }
}

class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        backtrace("",n,n);
        return res;
    }

    void backtrace(string s,int left,int right){
        // cout<<left<<","<<right<<endl;
        if(left==0&&right==0){
            res.push_back(s);
            return;
        }
        if(right<left)return;
        if(left==right){
            backtrace(s+"(",left-1,right);
        }else{
            if(left==0)backtrace(s+")",left,right-1);
            else{
                backtrace(s+"(",left-1,right);
                backtrace(s+")",left,right-1);
            }
        }
    }
};

int main(){
    Solution s =Solution();
    vector<string> res = s.generateParenthesis(3);
    print(res);
    return 0;
}