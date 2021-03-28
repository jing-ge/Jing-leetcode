// Given two strings S and T, return if thy equal when both
// are typed out. Any '#' that appears in the string counts as a backspace.nullptr

// examples:
// S = "ac#d" T = "ab#d" return true

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string simple(string &s){
        string res;
        for(auto &c:s){
            if(c=='#'){
                if(res.size()>0)
                res.pop_back();
            }else{
                res.push_back(c);
            }
        }
        return res;
    }
    bool backspaceCompare(string S, string T) {
        string a,b;
        a = simple(S);
        b = simple(T);
        return a==b;
    }
};

int main(){
    string S = "ab#c", T = "ad#c";
    Solution s;
    bool res = s.backspaceCompare(S,T);
    cout<<res<<endl;
    return 0;
}