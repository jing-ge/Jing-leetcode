// 1004. Max Consecutive Ones III
// Given an array A of 0s and 1s, we may change up to K values from 0 to 1.

// Return the length of the longest (contiguous) subarray that contains only 1s. 

 

// Example 1:

// Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
// Output: 6
// Explanation: 
// [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.
// Example 2:

// Input: A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
// Output: 10
// Explanation: 
// [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
// Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.
 

// Note:

// 1 <= A.length <= 20000
// 0 <= K <= A.length
// A[i] is 0 or 1 
// 通过次数28,047提交次数47,331

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int res = 0,k = 0,left = 0,right = 0;
        while(right<A.size()){
            while(k<K&&right<A.size()){
                if(A[right]==0){
                    k++;
                }
                right++;
            }
            while(right<A.size()&&A[right])right++;
            // cout<<left<<","<<right<<","<<k<<endl;
            res = max(res,right-left);
            if(k>0&&A[left]==0)k--;
            left++;
            if(left>right)right = left;
        }
        return res;
    }
};

int main(){
    vector<int> A = {0,0,1,1,0,0};
    int K = 0;
    Solution s;
    int res = s.longestOnes(A,K);
    cout<<res<<endl;
    return 0;
}