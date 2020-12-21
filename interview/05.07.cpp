// 面试题 05.07. Exchange LCCI
// Write a program to swap odd and even bits in an integer with as few instructions as possible (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, and so on).

// Example1:

//  Input: num = 2（0b10）
//  Output 1 (0b01)
// Example2:

//  Input: num = 3
//  Output: 3
// Note:

// 0 <= num <= 2^30 - 1
// The result integer fits into 32-bit integer.

#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
    int exchangeBits(int num) {
        bitset<32> n(num);
        for(int i=1;i<32;i+=2){
            if(n[i]!=n[i-1]){
                n[i].flip();
                n[i-1].flip();
            }
        }
        return (int)n.to_ulong();
    }
};

int main(){
    int num =3;
    Solution s = Solution();
    int res = s.exchangeBits(num);
    cout<<res<<endl;
    return res;
}