// 面试题 17.10. Find Majority Element LCCI
// A majority element is an element that makes up more than half of the items in an array. Given a positive integers array, find the majority element. If there is no majority element, return -1. Do this in O(N) time and O(1) space.

// Example 1:

// Input: [1,2,5,9,5,9,5,5,5]
// Output: 5
 

// Example 2:

// Input: [3,2]
// Output: -1
 

// Example 3:

// Input: [2,2,1,1,1,2,2]
// Output: 2
// 通过次数24,894提交次数44,098

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mid = nums.size()/2;
        int cnt = 0;
        for(int &i:nums){
            if(i==nums[mid])cnt++;
        }
        if(2*cnt>nums.size())return nums[mid];
        else return -1;
    }
};

int main(){
    Solution s = Solution();
    vector<int> nums = {1,2,5,9,5,9,5,5,5};
    int res = s.majorityElement(nums);
    cout<<res<<endl;
    return 0;
}