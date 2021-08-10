// 413. Arithmetic Slices
// An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

// For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
// Given an integer array nums, return the number of arithmetic subarrays of nums.

// A subarray is a contiguous subsequence of the array.

 

// Example 1:

// Input: nums = [1,2,3,4]
// Output: 3
// Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.
// Example 2:

// Input: nums = [1]
// Output: 0
 

// Constraints:

// 1 <= nums.length <= 5000
// -1000 <= nums[i] <= 1000
// 通过次数52,306提交次数76,830

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return 0;
        int d = nums[1]-nums[0],t = 0,res = 0;
        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1]==d){
                t++;
            }else{
                t = 0;
                d = nums[i]-nums[i-1];
            }
            res+=t;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,4};
    int res = s.numberOfArithmeticSlices(nums);
    cout<<res<<endl;
    return 0;
}