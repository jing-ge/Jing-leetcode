// 228. Summary Ranges
// You are given a sorted unique integer array nums.

// Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

// Each range [a,b] in the list should be output as:

// "a->b" if a != b
// "a" if a == b
 

// Example 1:

// Input: nums = [0,1,2,4,5,7]
// Output: ["0->2","4->5","7"]
// Explanation: The ranges are:
// [0,2] --> "0->2"
// [4,5] --> "4->5"
// [7,7] --> "7"
// Example 2:

// Input: nums = [0,2,3,4,6,8,9]
// Output: ["0","2->4","6","8->9"]
// Explanation: The ranges are:
// [0,0] --> "0"
// [2,4] --> "2->4"
// [6,6] --> "6"
// [8,9] --> "8->9"
// Example 3:

// Input: nums = []
// Output: []
// Example 4:

// Input: nums = [-1]
// Output: ["-1"]
// Example 5:

// Input: nums = [0]
// Output: ["0"]
 

// Constraints:

// 0 <= nums.length <= 20
// -231 <= nums[i] <= 231 - 1
// All the values of nums are unique.
// nums is sorted in ascending order.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if(n<1)return {};
        if(n==1)return {to_string(nums[0])};
        int start = nums[0],end = 0;
        vector<string> res;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                end = nums[i];
            }else{
                if(start>=end){
                    res.push_back(to_string(start));
                }else if(start<end){
                    res.push_back(to_string(start)+"->"+to_string(end));
                }
                start = nums[i];
            }
        }
        end = nums[n-1];
        if(start==end){
            res.push_back(to_string(start));
        }else{
            res.push_back(to_string(start)+"->"+to_string(end));
        }
        return res;
    }
};

int main(){
    vector<int> nums = {0};
    Solution s = Solution();
    vector<string> res = s.summaryRanges(nums);
    for(string &st:res){
        cout<<st<<endl;
    }
    return 0;
}