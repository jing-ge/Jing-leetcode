// 190. Reverse Bits
// Reverse bits of a given 32 bits unsigned integer.

// Note:

// Note that in some languages such as Java, there is no unsigned integer type. In this case, both input and output will be given as a signed integer type. They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
// In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above, the input represents the signed integer -3 and the output represents the signed integer -1073741825.
// Follow up:

// If this function is called many times, how would you optimize it?

 

// Example 1:

// Input: n = 00000010100101000001111010011100
// Output:    964176192 (00111001011110000010100101000000)
// Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.
// Example 2:

// Input: n = 11111111111111111111111111111101
// Output:   3221225471 (10111111111111111111111111111111)
// Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is 10111111111111111111111111111111.
 

// Constraints:

// The input must be a binary string of length 32
// 通过次数76,957提交次数118,687

#include <iostream>
#include <bitset>

using namespace std;

void print(bitset<32>& bs){
    for(int i=0;i<32;i++){
        cout<<bs[i];
    }
    cout<<endl;
}

class Solution {
public:
    const uint32_t M1 = 0x55555555;
    const uint32_t M2 = 0x33333333;
    const uint32_t M3 = 0x0f0f0f0f;
    const uint32_t M4 = 0x00ff00ff;
    uint32_t reverseBits1(uint32_t n) {
       bitset<32> bs(n);
    //    for(int i=0;i<32;i++){
    //        cout<<bs[i];
    //    } 
    //    cout<<endl;
       uint32_t res = 0;
       for(int i=0;i<32;i++){
           res<<=1;
           res|=bs[i];
       }
       return res;
    }
    uint32_t reverseBits(uint32_t n) {
        n = n>>1 & M1 |(n&M1)<<1;
        n = n>>2 & M2 |(n&M2)<<2;
        n = n>>4 & M3 |(n&M3)<<4;
        n = n>>8 & M4 |(n&M4)<<8;
        return n>>16|n<<16;
    }
};

int main(){
    uint32_t n = 1;
    Solution s;
    uint32_t res = s.reverseBits(n);
    cout<<res<<endl;
    return 0;
}