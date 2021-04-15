// 213. House Robber II
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
// Example 2:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 3:

// Input: nums = [0]
// Output: 0
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 1000
// 通过次数91,972提交次数220,182

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int robhelper(vector<int>&nums, int start, int end){
        int first = nums[start],second = max(first,nums[start+1]);
        for(int i=start+2;i<=end;i++){
            int tmp = second;
            second = max(second,first+nums[i]);
            first = tmp;
        }
        return second;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        return max(robhelper(nums,0,n-2),robhelper(nums,1,n-1));
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,3,2};
    int res = s.rob(nums);
    cout<<res<<endl;
    return 0;
}