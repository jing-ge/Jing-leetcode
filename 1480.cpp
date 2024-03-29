// 1480. Running Sum of 1d Array
// Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

// Return the running sum of nums.

 

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [1,3,6,10]
// Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
// Example 2:

// Input: nums = [1,1,1,1,1]
// Output: [1,2,3,4,5]
// Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
// Example 3:

// Input: nums = [3,1,2,10,1]
// Output: [3,4,6,16,17]
 

// Constraints:

// 1 <= nums.length <= 1000
// -10^6 <= nums[i] <= 10^6
// 通过次数125,164提交次数144,040

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(vector<int> &nums){
    for(int i:nums){
        cout<<i<<",";
    }
    cout<<endl;
}

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res;
        int tmp = 0;
        for(int &i:nums){
            tmp+=i;
            res.push_back(tmp);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,4};
    vector<int> res = s.runningSum(nums);
    print(res);
    return 0; 
}  