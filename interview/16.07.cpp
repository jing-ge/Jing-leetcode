// 面试题 16.07. Maximum LCCI
// Write a method that finds the maximum of two numbers. You should not use if-else or any other comparison operator.

// Example:

// Input:  a = 1, b = 2
// Output:  2
// 通过次数12,405提交次数16,896

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int maximum(int a, int b) {
        return (int)(((a+b)+abs(a-b))/2);
    }
};
int main(){
    Solution s = Solution();
    int res = s.maximum(1,2);
    cout<<res<<endl;
    return 0;
}