// 面试题 08.05. Recursive Mulitply LCCIWrite a recursive function to multiply two positive integers without using the * operator. You can use addition, subtraction, and bit shifting, but you should minimize the number of those operations.

// Example 1:

//  Input: A = 1, B = 10
//  Output: 10
// Example 2:

//  Input: A = 3, B = 4
//  Output: 12
// Note:

// The result will not overflow.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int res = 0;
    int multiply(int A, int B) {
        if(A==0||B==0)return 0;
        return dugui(A,B);
    }
    int dugui(int A,int B){
        if(B==0)return 0;
        return dugui(A,B-1)+A;
    }
    int multiply1(int A, int B) {
        if(A==0||B==0)return 0;
        dugui(A,B);
        return res;
    }
    void dugui1(int A,int B){
        if(B==0)return;
        res+=A;
        dugui(A,B-1);
    }
};

int main(){
    Solution s = Solution();
    int res = s.multiply(3,3);
    cout<<res<<endl;
    return 0;
}