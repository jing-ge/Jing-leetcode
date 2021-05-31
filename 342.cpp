// 342. Power of Four
// Given an integer n, return true if it is a power of four. Otherwise, return false.

// An integer n is a power of four, if there exists an integer x such that n == 4x.

 

// Example 1:

// Input: n = 16
// Output: true
// Example 2:

// Input: n = 5
// Output: false
// Example 3:

// Input: n = 1
// Output: true
 

// Constraints:

// -231 <= n <= 231 - 1
// å

#include <iostream>

using namespace std;
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<4)return false;
        int t = n;
        while(t%4==0){
            t = t/4;
        }
        if(t==1)return true;
        else return false;
    }
};

int main(){
    Solution s = Solution();
    int n = 13;
    int res = s.isPowerOfFour(n);
    cout<<res<<endl;
    return 0;
}