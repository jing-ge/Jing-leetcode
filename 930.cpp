// 930. Binary Subarrays With Sum
// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

// A subarray is a contiguous part of the array.

 

// Example 1:

// Input: nums = [1,0,1,0,1], goal = 2
// Output: 4
// Explanation: The 4 subarrays are bolded and underlined below:
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// Example 2:

// Input: nums = [0,0,0,0,0], goal = 0
// Output: 15
 

// Constraints:

// 1 <= nums.length <= 3 * 104
// nums[i] is either 0 or 1.
// 0 <= goal <= nums.length
// 通过次数16,352提交次数32,078

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum_map(vector<int>& nums, int goal) {
        int sum = 0;
        unordered_map<int,int> cnt;
        int res = 0;
        for(auto&num:nums){
            cnt[sum]++;
            sum+=num;
            res+=cnt[sum-goal];
        }
        return res;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int l1 = 0, l2 = 0, r = 0;
        int sum1 = 0, sum2 = 0;
        int res = 0;
        while(r<n){
            sum1+=nums[r];
            while(l1<=r&&sum1>goal){
                sum1-=nums[l1];
                l1++;
            }
            sum2+=nums[r];
            while (l2<=r&&sum2>=goal)
            {
                sum2-=nums[l2];
                l2++;
            }
            res+=l2-l1;
            r++;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,0,1,0,1};
    // vector<int> nums = {0,0,0,0,0};
    int goal = 2;
    int res = s.numSubarraysWithSum(nums,goal);
    cout<<res<<endl;
    return 0;
}