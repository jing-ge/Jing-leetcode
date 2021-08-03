// 50. Pow(x, n)
// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

// Example 1:

// Input: x = 2.00000, n = 10
// Output: 1024.00000
// Example 2:

// Input: x = 2.10000, n = 3
// Output: 9.26100
// Example 3:

// Input: x = 2.00000, n = -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

// Constraints:

// -100.0 < x < 100.0
// -231 <= n <= 231-1
// -104 <= xn <= 104
// 通过次数201,843提交次数536,336

#include <iostream>

using namespace std;

class Solution {
public:
    double quickPow(double x, long long N) {
        if(N==0)return 1;
        double res = 1.0,x_ = x;
        while (N>0)
        {
            if(N%2==1){
                res*=x_;
            }
            x_*=x_;
            N/=2;
        }
        return res;
    }
    double myPow(double x, int n) {
        long long N =n;
        return N>0?quickPow(x,N):1/quickPow(x,-N);
    }
};

int main(){
    double x = 2.1;
    int n = 3;
    Solution s;
    double res = s.myPow(x,n);
    cout<<res<<endl;
    return 0;
}