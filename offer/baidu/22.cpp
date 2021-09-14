#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn=1e6+100;
int a[maxn],b[maxn];
int dp[maxn][2];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    memset(dp,0x3f3f3f,sizeof(dp));
    dp[1][1] = 1;
    dp[1][0] = 0;
    for(int i=2;i<=n;i++){
        if(a[i]>a[i-1]){
            dp[i][0] = min(dp[i][0],dp[i-1][0]);
        }
        if(a[i]>b[i-1]){
            dp[i][0] = min(dp[i][0],dp[i-1][1]);
        }
        if(b[i]>a[i-1]){
            dp[i][1] = min(dp[i][1],dp[i-1][0]+1);
        }
        if(b[i]>b[i-1]){
            dp[i][1] = min(dp[i][1],dp[i-1][1]+1);
        }
    }
    if(dp[n][0]==1061109567&&dp[n][1]==1061109567){
        cout<<-1<<endl;
    }
    else{
        cout<<min(dp[n][0],dp[n][1])<<endl;
    }
    return 0;
}

