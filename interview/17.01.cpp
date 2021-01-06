// 面试题 17.01. Add Without Plus LCCI
// Write a function that adds two numbers. You should not use + or any arithmetic operators.

// Example:

// Input: a = 1, b = 1
// Output: 2
 

// Note:

// a and b may be 0 or negative.
// The result fits in 32-bit integer.
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int add(int a, int b) {
        while(b!=0){
            int carry = (unsigned int)(a&b)<<1;
            a^=b;
            b = carry ;
        }
        return a;
    }
};

int main(){
    Solution s = Solution();
    int res = s.add(1,1);
    cout<<res<<endl;
    return 0;
}