// 面试题 05.06. Convert Integer LCCI
// Write a function to determine the number of bits you would need to flip to convert integer A to integer B.

// Example1:

//  Input: A = 29 (0b11101), B = 15 (0b01111)
//  Output: 2
// Example2:

//  Input: A = 1，B = 2
//  Output: 2
// Note:

// -2147483648 <= A, B <= 2147483647

#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
    int convertInteger(int A, int B) {
        bitset<32> a(A);
        bitset<32> b(B);
        int res = 0;
        for(int i=0;i<32;i++){
            if(a[i]!=b[i])res++;
        }
        return res;
    }
};

int main(){
    int a = 1;
    int b = 2;
    Solution s = Solution();
    int res = s.convertInteger(a,b);
    cout<<res<<endl;
    return 0;
}