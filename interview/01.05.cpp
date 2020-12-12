// 面试题 01.05. One Away LCCI
// There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character. Given two strings, write a function to check if they are one edit (or zero edits) away.

//  

// Example 1:

// Input: 
// first = "pale"
// second = "ple"
// Output: True
// Example 2:

// Input: 
// first = "pales"
// second = "pal"
// Output: False


#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(vector<vector<int>> dp){
    for(auto i:dp){
        for(auto j:i){
            cout<<j<<",";
        }
        cout<<endl;
    }
}

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int d = first.size()-second.size();
        if(d==0){
            int cnt = 0;
            for(int i=0;i<first.size();i++){
                if(first[i]!=second[i])cnt++;
                if(cnt>1)return false;
            }
            return true;
        }else if(d==1){
            int i=0,j=0,cnt = 0;
            while(i<first.size()&&j<second.size()){
                cout<<i<<j<<endl;
                if(cnt>1)return false;
                if(first[i]!=second[j]){
                    i++;
                    cnt++;
                    continue;
                }
                i++;j++;
            }
            if(cnt>1)return false;
            return true;
        }else if(d==-1){
            int i=0,j=0,cnt = 0;
            while(i<first.size()&&j<second.size()){
                if(cnt>1)return false;
                if(first[i]!=second[j]){
                    j++;
                    cnt++;
                    continue;
                }
                i++;j++;
            }
            if(cnt>1)return false;
            return true;
        }
        else{
            return false;
        }
    }
    bool oneEditAway2(string first, string second) {
        int d = first.size()-second.size();
        if(d>-2&&d<2){
            vector<vector<int>> dp(first.size()+1,vector<int> (second.size()+1,0));
            for(int i=1;i<=first.size();i++){
                for(int j = 1;j<=second.size();j++){
                    if(first[i-1]==second[i-1]){
                        dp[i][j] = dp[i-1][j-1];
                    }else{
                        dp[i][j] = min(dp[i-1][j]+1,dp[i-1][j-1]+1,dp[i][j-1]+1);
                    }
                }
            }
            print(dp);
            cout<<"-------"<<endl;
            return dp[first.size()+1][second.size()+1]>1;
        }
        return false;
    }
    int min(int a,int b,int c){
        a = a>b?b:a;
        a = a>c?c:a;
        return a;
    }
};



int main()
{
    Solution s = Solution();
    string first = "islander",second = "slander";
    bool res = s.oneEditAway2(first,second);
    cout<<res<<endl;
    return 0;

}