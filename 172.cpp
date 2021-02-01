// 172. Factorial Trailing Zeroes
// Given an integer n, return the number of trailing zeroes in n!.

// Follow up: Could you write a solution that works in logarithmic time complexity?

 

// Example 1:

// Input: n = 3
// Output: 0
// Explanation: 3! = 6, no trailing zero.
// Example 2:

// Input: n = 5
// Output: 1
// Explanation: 5! = 120, one trailing zero.
// Example 3:

// Input: n = 0
// Output: 0
 

// Constraints:

// 0 <= n <= 104
// 通过次数60,733提交次数146,496

#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        if(n<5)return 0;
        int res = 0;
        int t = 5;
        while(t<=n){
            res += n/t;
            t = t*5;
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 10;
    int res = s.trailingZeroes(n);
    cout<<res<<endl;
    return 0;
}