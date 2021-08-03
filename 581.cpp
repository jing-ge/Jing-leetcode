// 581. Shortest Unsorted Continuous Subarray
// Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

// Return the shortest such subarray and output its length.

 

// Example 1:

// Input: nums = [2,6,4,8,10,9,15]
// Output: 5
// Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
// Example 2:

// Input: nums = [1,2,3,4]
// Output: 0
// Example 3:

// Input: nums = [1]
// Output: 0
 

// Constraints:

// 1 <= nums.length <= 104
// -105 <= nums[i] <= 105
 

// Follow up: Can you solve it in O(n) time complexity?
// 通过次数68,841提交次数180,884

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray_sort(vector<int>& nums) {
        if(is_sorted(nums.begin(),nums.end()))
        return 0;
        vector<int> cnums(nums);
        sort(nums.begin(),nums.end());
        int left = 0,right = nums.size()-1;
        while (nums[left]==cnums[left])
        {
            left++;
        }
        while(nums[right]==cnums[right]){
            right--;
        }
        return right-left+1;
    }
    int findUnsortedSubarray(vector<int>& nums) {
        int left = -1,right = -1,n = nums.size();
        int maxn = INT32_MIN,minn = INT32_MAX;
        for(int i=0;i<nums.size();i++){
            if(maxn<=nums[i]){
                maxn = nums[i];
            }else{
                right = i;
            }
            if(minn>=nums[n-i-1]){
                minn = nums[n-i-1];
            }else{
                left = n-i-1;
            }
        }
        return right==-1?0:right-left+1;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,6,4,8,10,9,15};
    int res = s.findUnsortedSubarray(nums);
    cout<<res<<endl;
    return 0;
}