// 1018. Binary Prefix Divisible By 5
// Given an array A of 0s and 1s, consider N_i: the i-th subarray from A[0] to A[i] interpreted as a binary number (from most-significant-bit to least-significant-bit.)

// Return a list of booleans answer, where answer[i] is true if and only if N_i is divisible by 5.

// Example 1:

// Input: [0,1,1]
// Output: [true,false,false]
// Explanation: 
// The input numbers in binary are 0, 01, 011; which are 0, 1, and 3 in base-10.  Only the first number is divisible by 5, so answer[0] is true.
// Example 2:

// Input: [1,1,1]
// Output: [false,false,false]
// Example 3:

// Input: [0,1,1,1,1,1]
// Output: [true,false,false,false,true,false]
// Example 4:

// Input: [1,1,1,0,1]
// Output: [false,false,false,false,false]
 

// Note:

// 1 <= A.length <= 30000
// A[i] is 0 or 1
// 通过次数15,464提交次数31,178

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //会溢出
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool>res ;
        int t=0;
        for(int i:A){
            t = ((t<<1)+i)%5;
            if(t==0){res.push_back(true);}
            else res.push_back(false);
        }
        return res;
    }
};

int main(){
    Solution s = Solution();
    vector<int> A = {0,1,1};
    vector<bool> res = s.prefixesDivBy5(A);
    for(auto i:res)cout<<i<<",";
    cout<<endl;
    return 0;
}