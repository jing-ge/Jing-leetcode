给定一个矩阵，从左上角走到右下角，每次只能向右或者向下，每一条路径上所有元素的乘积为价值
求所有路径上最大的价值
结果对10E9+7取模

#include <iostream>
#include <vector>

using namespace std;
void print(vector<vector<int>>&data){
    for(auto t:data){
        for(int i:t){
            cout<<i<<",";
        }
        cout<<endl;
    }
}
int main(){
    long long mod = 1000000007;
    int n,m;
    cin>>n>>m;
    vector<vector<int>> data = vector<vector<int>>(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>data[i][j];
        }
    }
    // print(data);
    vector<vector<long long>> dp = vector<vector<long long>>(n,vector<long long>(m,0));
    dp[0][0] = data[0][0];
    for(int i=1;i<n;i++){
        dp[i][0] = dp[i-1][0]*data[i][0];
    }
    for(int j=1;j<m;j++){
        dp[0][j] = dp[0][j-1]*data[0][j];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(abs(dp[i-1][j])>abs(dp[i][j-1]){
                dp[i][j] =dp[i-1][j]*data[i][j]%mod;
            }else{
                dp[i][j] =dp[i][j-1]*data[i][j]%mod;
            }
        }
    }
    // print(dp);
    long long res = dp[n-1][m-1]>0?dp[n-1][m-1]:-1;
    cout<<res%mod<<endl;
    
    return 0;
}