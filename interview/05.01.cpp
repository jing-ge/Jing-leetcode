// 面试题 05.01. Insert Into Bits LCCIYou are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a method to insert M into N such that M starts at bit j and ends at bit i. You can assume that the bits j through i have enough space to fit all of M. That is, if M = 10011, you can assume that there are at least 5 bits between j and i. You would not, for example, have j = 3 and i = 2, because M could not fully fit between bit 3 and bit 2.

// Example1:

//  Input: N = 10000000000, M = 10011, i = 2, j = 6
//  Output: N = 10001001100
// Example2:

//  Input:  N = 0, M = 11111, i = 0, j = 4
//  Output: N = 11111


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int insertBits(int N, int M, int i, int j) {
        int mask=((1<<(j-i+1))-1)<<i;
       mask=~mask;
       N&=mask;
       M=M<<i;
       return M|N;
    }
};

int main(){
    int N=1143207437,M = 1017033,i=11,j=31;
    Solution s = Solution();
    int res = s.insertBits(N,M,i,j);
    cout<<res<<endl;
    return 0;
}