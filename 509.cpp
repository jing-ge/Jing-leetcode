// 509. Fibonacci Number
// The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1.
// Given n, calculate F(n).

 

// Example 1:

// Input: n = 2
// Output: 1
// Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
// Example 2:

// Input: n = 3
// Output: 2
// Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
// Example 3:

// Input: n = 4
// Output: 3
// Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
 

// Constraints:

// 0 <= n <= 30
// 通过次数104,302提交次数156,389

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int fib(int N) {
        if(N==1||N==2)return 1;
        int pre=1,cur=1;
        int l = 0;
        for(int i=3;i<=N;i++)
        {
                l = pre + cur;
                pre = cur;
                cur = l;
        }
        return l;
    }
};

int main(){
    Solution s = Solution();
    int res = s.fib(5);
    cout<<res<<endl;
    return 0;
}