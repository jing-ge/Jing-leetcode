#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_huiwen(string &s){
    int n = s.size();
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[n-i-1])return false;
    }
    return true;
}

int main(){
    string str = "abba";
    int res = is_huiwen(str);
    cout<<res<<endl;

    str = "aabb";
    res = is_huiwen(str);
    cout<<res<<endl;

    str = "acabbaca";
    res = max_huiwen(str);
    return 0;

}



int max_huiwen(string &s){
    if (s[i]==s[j])
        dp[i][j] = dp[i+1][j-1];
    else 
        dp[i][j] = 0;
}