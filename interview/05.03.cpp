// 面试题 05.03. Reverse Bits LCCIYou have an integer and you can flip exactly one bit from a 0 to a 1. Write code to find the length of the longest sequence of 1s you could create.

// Example 1:

// Input: num = 1775(110111011112)
// Output: 8
// Example 2:

// Input: num = 7(01112)
// Output: 4

#include <iostream>

using namespace std;

class Solution {
public:
    int reverseBits(int num) {
        int l=0,r=0,Max = 0;
        for (int i = 0; i < 32; i++)
        {
            if(num&1)r++;
            else l=r+1,r=0;
            Max = max(l+r,Max);
            num>>=1;
        }
        return Max;
    }
};

int main(){
    int num = 1775;
    Solution s = Solution();
    int res = s.reverseBits(num);
    cout<<res<<endl;
    return 0;
}