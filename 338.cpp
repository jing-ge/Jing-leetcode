// 338. Counting Bits
// Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

// Example 1:

// Input: 2
// Output: [0,1,1]
// Example 2:

// Input: 5
// Output: [0,1,1,2,1,2]
// Follow up:

// It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
// Space complexity should be O(n).
// Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
// 通过次数78,085提交次数100,999

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits1(int num) {
        vector<int> res(num+1);
        for(int i=0;i<=num;i++){
            res[i] = count(i);
        }
        return res;
    }
    int count(int x){
        int res = 0;
        while (x > 0)
        {
            x &= (x-1);
            res++;
        }
        return res;
    }
    vector<int> countBits2(int num) {
        vector<int> dp(num+1,0);
        for(int i=1;i<=num;i++){
            if(i&1){
                dp[i] = dp[i-1] + 1;
            }else{
                dp[i] = dp[i>>1];
            }
        }
        return dp;
    }
    vector<int> countBits3(int num) {
        vector<int> dp(num+1,0);
        int highbit = 0; 
        for(int i=1;i<=num;i++){
            if((i&(i-1))==0){
                highbit = i;
            }
            dp[i] = dp[i-highbit]+1;
            
        }
        return dp;
    }
    vector<int> countBits4(int num) {
        vector<int> dp(num+1,0);
        for(int i=1;i<=num;i++){
            dp[i] = dp[i>>1] + (i&1); 
        }
        return dp;
    }
    vector<int> countBits(int num) {
        vector<int> dp(num+1,0);
        for(int i=1;i<=num;i++){
            dp[i] = dp[i&(i-1)] + 1; 
        }
        return dp;
    }
};

int main(){
    Solution s;
    int num = 2;
    vector<int> res = s.countBits(num);
    for(int i:res)cout<<i<<",";
    cout<<endl;
    return 0;
}