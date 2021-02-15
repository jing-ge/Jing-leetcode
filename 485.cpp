// 485. Max Consecutive Ones
// Given a binary array, find the maximum number of consecutive 1s in this array.

// Example 1:
// Input: [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive 1s.
//     The maximum number of consecutive 1s is 3.
// Note:

// The input array will only contain 0 and 1.
// The length of input array is a positive integer and will not exceed 10,000
// 通过次数87,611提交次数147,259

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int t = 0;
        for(int &i:nums){
            if(i){
                t++;
            }else{
                res = max(res,t);
                t = 0;
            }
        }
        res = max(res,t);
        return res;

    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,0,1,1,1};
    int  res = s.findMaxConsecutiveOnes(nums);
    cout<<res<<endl;
    return 0;
}