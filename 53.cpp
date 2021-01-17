// 53. Maximum Subarray
// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

 

// Example 1:

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.
// Example 2:

// Input: nums = [1]
// Output: 1
// Example 3:

// Input: nums = [0]
// Output: 0
// Example 4:

// Input: nums = [-1]
// Output: -1
// Example 5:

// Input: nums = [-100000]
// Output: -100000
 

// Constraints:

// 1 <= nums.length <= 3 * 104
// -105 <= nums[i] <= 105
 

// Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
// 通过次数399,659提交次数752,891

#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> & nums){
    for(int i:nums)cout<<i<<",";
    cout<<endl;
}

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        int res = nums[0];
        dp[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            dp[i] = max(dp[i-1]+nums[i],nums[i]);
            res = max(dp[i],res);
        }
        print(nums);
        print(dp);
        return res;
    }
};

int main(){

    Solution s = Solution();
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int res = s.maxSubArray(nums);
    cout<<res<<endl;
    return 0;
}