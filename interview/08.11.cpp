// 面试题 08.11. Coin LCCIGiven an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents), and pennies (1 cent), write code to calculate the number of ways of representing n cents. (The result may be large, so you should return it modulo 1000000007)

// Example1:

//  Input: n = 5
//  Output: 2
//  Explanation: There are two ways:
// 5=5
// 5=1+1+1+1+1
// Example2:

//  Input: n = 10
//  Output: 4
//  Explanation: There are four ways:
// 10=10
// 10=5+5
// 10=5+1+1+1+1+1
// 10=1+1+1+1+1+1+1+1+1+1
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mod = 1000000007;
    int coins[4] = {25,10,5,1};
    int waysToChange(int n) {
        vector<int> f(n+1);
        f[0] = 1;
        for(int c=0;c<4;c++){
            int coin = coins[c];
            for(int i=coin;i<=n;i++){
                f[i] = (f[i]+f[i-coin])%mod;
            }
        }
        return f[n];
    }
};

int main(){
    Solution s = Solution();
    int res = s.waysToChange(5);
    cout<<res<<endl;
    return 0;
}