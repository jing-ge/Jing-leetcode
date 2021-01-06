// 525. Contiguous Array
// Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

// Example 1:
// Input: [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
// Example 2:
// Input: [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
// Note: The length of the given binary array will not exceed 50,000.
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> map;
        map[0]=-1;
        int maxlength = 0;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i]==0?-1:1;
            if(map.find(sum)!=map.end()){
                maxlength = max(maxlength,i-map[sum]);
            }else{
                map[sum] = i;
            }
        }
        return maxlength;
    }
};

int main(){
    Solution s = Solution();
    vector<int> nums = {0,1,0};
    int res = s.findMaxLength(nums);
    cout<<res<<endl;
    return 0;
}