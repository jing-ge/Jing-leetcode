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
    bool backspaceCompare1(string S, string T) {
        string a,b;
        a = simple(S);
        b = simple(T);
        return a==b;
    }
    bool backspaceCompare(string S, string T) {
        int p1 = S.size()-1,p2 = T.size()-1;
        int cnt1 = 0,cnt2 = 0;
        while (p1>=0||p2>=0)
        {
            while(p1>=0){
                if(S[p1]=='#'){cnt1++;p1--;}
                else if(cnt1>0){p1--;cnt1--;}
                else break;
            }
            while(p2>=0){
                if(T[p2]=='#'){cnt2++;p2--;}
                else if(cnt2>0){p2--;cnt2--;}
                else break;
            }
            if(p1>=0&&p2>=0&&S[p1]!=T[p2])return false;
            if((p1>=0)!=(p2>=0))return false;
            p1--;
            p2--;
        }
        return true;
    }
};

int main(){
    string S = "ab##", T = "c#d#";
    Solution s;
    bool res = s.backspaceCompare(S,T);
    cout<<res<<endl;
    return 0;
}