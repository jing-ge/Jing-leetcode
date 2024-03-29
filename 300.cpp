// 300. Longest Increasing Subsequence
// Given an integer array nums, return the length of the longest strictly increasing subsequence.

// A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

 

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4
// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1
 

// Constraints:

// 1 <= nums.length <= 2500
// -104 <= nums[i] <= 104
 

// Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS_dp(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        vector<int> dp(n,0);
        int res = 0;
        for(int i=0;i<n;i++){
            dp[i] = 1;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i])
                dp[i] = max(dp[i],dp[j]+1);
            }
            res = max(res,dp[i]);
        }
        return res;
    }
    int lengthOfLIS(vector<int>& nums) {
        int len = 1,n = (int)nums.size();
        if(n==0)return 0;
        vector<int> d;
        d.push_back(nums[0]);
        for(int i=0;i<n;i++){
            if(nums[i]>d[d.size()-1]){
                d.push_back(nums[i]);
            }else{
                auto it = lower_bound(d.begin(),d.end(),nums[i]);
                if(it!=d.end()){
                    *it=nums[i];
                }else{
                    d.push_back(nums[i]);
                }
            }
        }
        return d.size();
    }
};

int main(){
    Solution s;
    vector<int> nums = {10,9,2,5,3,7,101,18};
    int res = s.lengthOfLIS(nums);
    cout<<res<<endl;
    return 0;
}