// 1137. N-th Tribonacci Number
// The Tribonacci sequence Tn is defined as follows: 

// T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

// Given n, return the value of Tn.

 

// Example 1:

// Input: n = 4
// Output: 4
// Explanation:
// T_3 = 0 + 1 + 1 = 2
// T_4 = 1 + 1 + 2 = 4
// Example 2:

// Input: n = 25
// Output: 1389537
 

// Constraints:

// 0 <= n <= 37
// The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.
// 通过次数58,522提交次数97,695

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int tribonacci_r(int n) {
        if(n<=2){
            if(n==0)return 0;
            else return 1;
        }
        return tribonacci_r(n-1)+tribonacci_r(n-2)+tribonacci_r(n-3);
    }
    int tribonacci_dp(int n) {
        vector<int> dp = {0,1,1};
        if(n<=2)return dp[n];
        for(int i=3;i<=n;i++){
            dp.push_back(dp[i-1]+dp[i-2]+dp[i-3]);
        }
        return dp[n];
    }
    int tribonacci_dp_c(int n) {
        if(n<=2){
            if(n==0)return 0;
            else return 1;
        }
        int a=0,b=1,c=1,t;
        for(int i=3;i<=n;i++){
            t = a+b+c;
            a = b;
            b = c;
            c = t;
        }
        return t;
    }
    int tribonacci(int n) {
        if(n<=2){
            if(n==0)return 0;
            else return 1;
        }
        vector<vector<long>> mat = {{1,1,1},{1,0,0},{0,1,0}};
        vector<vector<long>> res = matpow(mat,n);
        return res[2][0]+res[2][1];
    }
    vector<vector<long>> matpow(vector<vector<long>> &a,int n){
        vector<vector<long>> res = {{1,0,0},{0,1,0},{0,0,1}};
        while(n>0){
            if((n&1)==1){
                res = mm(res,a);
            }
            n>>=1;
            a = mm(a,a);
        }
        return res;
    }
    vector<vector<long>> mm(vector<vector<long>> &a,vector<vector<long>> &b){
        int m = a.size(),n = b[0].size();
        vector<vector<long>> res(m,vector<long>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res[i][j] = a[i][0]*b[0][j] + a[i][1]*b[1][j] + a[i][2]*b[2][j];
            }
        }
        return res;
    }
};

int main(){
    int n = 35;
    Solution s;
    int res =s.tribonacci(n);
    cout<<res<<endl;
    return 0;
}