// 907. Sum of Subarray Minimums
// Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 

// Example 1:

// Input: arr = [3,1,2,4]
// Output: 17
// Explanation: 
// Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
// Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
// Sum is 17.
// Example 2:

// Input: arr = [11,81,94,43,3]
// Output: 444
 

// Constraints:

// 1 <= arr.length <= 3 * 104
// 1 <= arr[i] <= 3 * 104
// 通过次数7,406提交次数24,295
#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    const int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> s;
        arr.push_back(-1);
        int n = arr.size();
        int res = 0;
        for(int i=0;i<n;i++){
            while(!s.empty()&&arr[s.top()]>=arr[i]){
                int idx = s.top();
                s.pop();
                int prev = idx - (s.empty()?-1:s.top());
                int after = i - idx;
                res = (res + (long)arr[idx]*prev*after)%mod;
            }
            s.push(i);
        }
        return res;
    }
};

int main(){
    vector<int> arr = {3,1,2,4};
    Solution s;
    int res = s.sumSubarrayMins(arr);
    cout<<res<<endl;
    return 0;
}