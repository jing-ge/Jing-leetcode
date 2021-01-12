// 260. Single Number III
// Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

// Follow up: Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

 

// Example 1:

// Input: nums = [1,2,1,3,2,5]
// Output: [3,5]
// Explanation:  [5, 3] is also a valid answer.
// Example 2:

// Input: nums = [-1,0]
// Output: [-1,0]
// Example 3:

// Input: nums = [0,1]
// Output: [1,0]
 

// Constraints:

// 2 <= nums.length <= 3 * 104
// -231 <= nums[i] <= 231 - 1
// Each integer in nums will appear twice, only two integers will appear once.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size()<2)return {};
        int res = 0;
        for(int &x:nums)res^=x;
        int t=0;
        while(true){
            if((res>>t&1)==1)break;
            t++;
        }
        int a=0,b=0;
        for(int &x:nums){
            if((x>>t&1)==0)a^=x;
            else b^=x;
        }
        return {a,b};
    }
};

int main(){
    Solution s = Solution();
    vector<int> nums = {1,2,1,3,2,5};
    vector<int> res = s.singleNumber(nums);
    cout<<res[0]<<","<<res[1]<<endl;
    return 0;
}