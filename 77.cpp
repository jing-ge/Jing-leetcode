// 77. Combinations
// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

// You may return the answer in any order.

 

// Example 1:

// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]
// Example 2:

// Input: n = 1, k = 1
// Output: [[1]]
 

// Constraints:

// 1 <= n <= 20
// 1 <= k <= n
// 通过次数141,809提交次数185,063

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    vector<vector<int>> combine(int n, int k) {
        backtrace(1,n,k);
        return res;
    }
    void backtrace(int i,int n,int k){
        if(tmp.size()==k){
            res.push_back(tmp);
            return;
        }
        for(int t = i;t<=n;t++){
            tmp.push_back(t);
            backtrace(t+1,n,k);
            tmp.pop_back();
        }
    }
};

int main(){
    Solution s;
    int n=1,k=1;
    vector<vector<int>>res =  s.combine(n,k);
    for (auto t:res){
        for(int i:t)cout<<i<<",";
        cout<<endl;
    }
    return 0;
}