// 137. Single Number II
// Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

 

// Example 1:

// Input: nums = [2,2,3,2]
// Output: 3
// Example 2:

// Input: nums = [0,1,0,1,0,1,99]
// Output: 99
 

// Constraints:

// 1 <= nums.length <= 3 * 104
// -231 <= nums[i] <= 231 - 1
// Each element in nums appears exactly three times except for one element which appears once.
 

// Follow up: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

// 通过次数48,684提交次数71,203

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i=0;i<32;i++){
            int cnt = 0;
            int bit = 1<<i;
            for(int &x:nums){
                if(x&bit)cnt++;
            }
            if(cnt%3)res|=bit;
        }
        return res;
    }
};

int main(){
    vector<int> nums = {0,1,0,1,0,1,99};
    Solution s = Solution();
    int res =s.singleNumber(nums);
    cout<<res<<endl;
    return 0;
}