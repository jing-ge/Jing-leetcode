// 643. Maximum Average Subarray I
// Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.

// Example 1:

// Input: [1,12,-5,-6,50,3], k = 4
// Output: 12.75
// Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
 

// Note:

// 1 <= k <= n <= 30,000.
// Elements of the given array will be in the range [-10,000, 10,000].
 

// 通过次数43,586提交次数97,466
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        double res = sum/k;
        for(int i=k;i<nums.size();i++){
            sum+=nums[i];
            sum-=nums[i-k];
            res = max(res,sum/k);
        }
        return res;

    }
};

int main(){
    int k = 4;
    vector<int> nums = {1,12,-5,-6,50,3};
    Solution s;
    double res = s.findMaxAverage(nums,k);
    cout<<res<<endl;
    return 0;
}