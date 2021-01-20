// 628. Maximum Product of Three Numbers
// Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: 6
// Example 2:

// Input: nums = [1,2,3,4]
// Output: 24
// Example 3:

// Input: nums = [-1,-2,-3]
// Output: -6
 

// Constraints:

// 3 <= nums.length <= 104
// -1000 <= nums[i] <= 1000
// 通过次数41,231提交次数81,137

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumProduct1(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a = nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];
        int b = nums[nums.size()-1]*nums[0]*nums[1];
        return a>b?a:b;
    }
    int maximumProduct(vector<int>& nums) {
        int min1 = INT32_MAX,min2 = INT32_MAX;
        int max1 = INT32_MIN, max2 = INT32_MIN, max3 = INT32_MIN;
        for(int &x:nums){
            if(x<min1){
                min2 = min1;
                min1 = x;
            }else if(x<min2){
                min2 = x;
            }
            if(x>max1){
                max3 = max2;
                max2 = max1;
                max1 = x;
            }else if(x>max2){
                max3 = max2;
                max2 = x;
            }else if(x>max3){
                max3 = x;
            }
        }
        int t1 = max1*max2*max3,t2 = max1*min1*min2;
        return max(t1,t2);
    }
};

int main(){

    vector<int> nums = {1,2,3,4};
    Solution s = Solution();
    int res = s.maximumProduct(nums);
    cout<<res<<endl;
    return 0;
}