// 面试题 17.04. Missing Number LCCI
// An array contains all the integers from 0 to n, except for one number which is missing.  Write code to find the missing integer. Can you do it in O(n) time?

// Note: This problem is slightly different from the original one the book.

// Example 1:

// Input: [3,0,1]
// Output: 2
 

// Example 2:

// Input: [9,6,4,2,3,5,7,0,1]
// Output: 8

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s = 0,ss = 0,i=0;
        for(;i<nums.size();i++){
            s+=nums[i];
            ss+=i;
        }
        ss+=i;
        return ss-s;
    }
    int missingNumber2(vector<int>& nums) {
        int res = 0,i=0;
        for(;i<nums.size();i++){
            res ^= i;
            res ^= nums[i];
        }
        res ^= i;
        return res;
    }
};

int main(){
    Solution s = Solution();
    vector<int> nums = {3,0,1};
    int res = s.missingNumber2(nums);
    cout<<res<<endl;
    return 0;
}