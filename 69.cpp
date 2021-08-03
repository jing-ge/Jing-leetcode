// 69. Sqrt(x)
// Given a non-negative integer x, compute and return the square root of x.

// Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

// Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.

 

// Example 1:

// Input: x = 4
// Output: 2
// Example 2:

// Input: x = 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
 

// Constraints:

// 0 <= x <= 231 - 1
// 通过次数351,496提交次数894,451

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int mySqrt_(int x) {
        int l = 0,r = x,res = -1;
        while (l<=r)
        {
            int mid = l + (r-l)/2;
            long t = (long)mid*mid,tt=(long)(mid+1)*(mid+1);
            if(t<=x&&tt>x)return mid;
            if(t<=x){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return res;
    }
    int mySqrt(int x) {
        if(x==0)return 0;
        double C = x,x0 = x;
        while (true)
        {
            double xi = 0.5*(x0+C/x0);
            if(fabs(x0-xi)<1e-7){
                break;
            }
            x0 = xi;
        }
        return (int)x0;
    }
};

int main(){
    Solution s;
    int x = 4;
    int res =s.mySqrt(x);
    cout<<res<<endl;
    return 0;
}