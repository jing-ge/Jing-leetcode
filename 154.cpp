// 154. Find Minimum in Rotated Sorted Array II
// Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:

// [4,5,6,7,0,1,4] if it was rotated 4 times.
// [0,1,4,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

// Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.

 

// Example 1:

// Input: nums = [1,3,5]
// Output: 1
// Example 2:

// Input: nums = [2,2,2,0,1]
// Output: 0
 

// Constraints:

// n == nums.length
// 1 <= n <= 5000
// -5000 <= nums[i] <= 5000
// nums is sorted and rotated between 1 and n times.
 

// Follow up: This is the same as Find Minimum in Rotated Sorted Array but with duplicates. Would allow duplicates affect the run-time complexity? How and why?
// 通过次数61,270提交次数119,303

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin1(vector<int>& nums) {
        int res = INT32_MAX;
        for(int i:nums){
            res = min(res,i);
        }
        return res;
    }
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1,mid;
        while (l<r)
        {
            mid = l+(r-l)/2;
            if(nums[mid]<nums[r]){
                r = mid;
            }else if(nums[mid]>nums[r]){
                l = mid+1;
            }else{
                r-=1;
            }
        }
        return nums[l];
    }
};

int main(){
    vector<int> nums = {1,3,5};
    Solution s;
    int res = s.findMin(nums);
    cout<<res<<endl;
    return 0;
}