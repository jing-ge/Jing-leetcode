// 面试题 16.26. Calculator LCCI
// Given an arithmetic equation consisting of positive integers, +, -, * and / (no paren­theses), compute the result.

// The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

// Example 1:

// Input: "3+2*2"
// Output: 7
// Example 2:

// Input: " 3/2 "
// Output: 1
// Example 3:

// Input: " 3+5 / 2 "
// Output: 5
// Note:

// You may assume that the given expression is always valid.
// Do not use the eval built-in library function.
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int cal(string &s, int l, int r){
        for(int i=r;i>=l;i--){
            if(s[i]=='+')return cal(s,l,i-1)+cal(s,i+1,r);
            if(s[i]=='-')return cal(s,l,i-1)-cal(s,i+1,r);
        }
        for(int i=r;i>=l;i--){
            if(s[i]=='*')return cal(s,l,i-1)*cal(s,i+1,r);
            if(s[i]=='/')return cal(s,l,i-1)/cal(s,i+1,r);
        }
        return stoi(s.substr(l,r-l+1));
    }
    int calculate(string s) {
        if(s.empty()) return 0;
        return cal(s,0,s.size()-1);
    }
};

int main(){
    Solution s = Solution();
    int res = s.calculate("2*3*4");
    cout<<res<<endl;
    return 0;
}