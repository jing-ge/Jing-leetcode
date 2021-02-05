// 60. Permutation Sequence
// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

 

// Example 1:

// Input: n = 3, k = 3
// Output: "213"
// Example 2:

// Input: n = 4, k = 9
// Output: "2314"
// Example 3:

// Input: n = 3, k = 1
// Output: "123"
 

// Constraints:

// 1 <= n <= 9
// 1 <= k <= n!
// 通过次数72,056提交次数138,839
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> jiecheng;
        jiecheng.push_back(1);
        for(int i=1;i<n;i++){
            jiecheng.push_back(jiecheng[jiecheng.size()-1]*i);
        }
        --k;
        string res;
        vector<int> valid(n+1,1);
        for(int i=1;i<=n;i++){
            int order = k/jiecheng[n-i]+1;
            for(int j=1;j<=n;j++){
                order -= valid[j];
                if(!order){
                    res+= (j+'0');
                    valid[j] = 0;
                    break;
                }
            }
            k%= jiecheng[n-i];
        }
        return res;
    }
};

int main(){
    Solution s;
    int n=3,k=3;
    string res = s.getPermutation(n,k);
    cout<<res<<endl;
    return 0;
}