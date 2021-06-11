// 494. Target Sum
// You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.

 

// Example 1:

// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3
// Example 2:

// Input: nums = [1], target = 1
// Output: 1
 

// Constraints:

// 1 <= nums.length <= 20
// 0 <= nums[i] <= 1000
// 0 <= sum(nums[i]) <= 1000
// -1000 <= target <= 1000
// 通过次数102,925提交次数214,038

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums,target,0);
    }

    int dfs(vector<int> &nums,int target,int left){
        if(target==0 && left == nums.size())return 1;
        if(left>=nums.size())return 0;
        int res = 0;
        res+=dfs(nums,target-nums[left],left+1);
        res+=dfs(nums,target+nums[left],left+1);
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,1,1,1};
    int target = 3;
    int res = s.findTargetSumWays(nums,target);
    cout<<res<<endl;
    return 0;
}