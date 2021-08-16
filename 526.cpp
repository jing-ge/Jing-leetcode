// 526. Beautiful Arrangement
// Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:

// perm[i] is divisible by i.
// i is divisible by perm[i].
// Given an integer n, return the number of the beautiful arrangements that you can construct.

 

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: 
// The first beautiful arrangement is [1,2]:
//     - perm[1] = 1 is divisible by i = 1
//     - perm[2] = 2 is divisible by i = 2
// The second beautiful arrangement is [2,1]:
//     - perm[1] = 2 is divisible by i = 1
//     - i = 2 is divisible by perm[2] = 1
// Example 2:

// Input: n = 1
// Output: 1
 

// Constraints:

// 1 <= n <= 15
// 通过次数17,512提交次数25,141

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> match;
    vector<int> vis;
    int nums;
    void backtrace(int index,int n){
        if(index==n+1){
            nums++;
            return;
        }
        for(int &t:match[index]){
            if(!vis[t]){
                vis[t] = 1;
                backtrace(index+1,n);
                vis[t] = 0;
            }
        }
        return;
    }
    int countArrangement(int n) {
        nums = 0;
        match.resize(n+1);
        vis.resize(n+1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i%j==0||j%i==0){
                    match[i].push_back(j);
                }
            }
        }
        backtrace(1,n);
        return nums;
    }
};

int main(){
    Solution s;
    int n = 2;
    int res = s.countArrangement(n);
    cout<<res<<endl;
    return 0;
}