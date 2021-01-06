// Design an algorithm to find all pairs of integers within an array which sum to a specified value.

// Example 1:

// Input: nums = [5,6,5], target = 11
// Output: [[5,6]]
// Example 2:

// Input: nums = [5,6,5,6], target = 11
// Output: [[5,6],[5,6]]
// Note:

// nums.length <= 100000
// 通过次数6,790提交次数14,779

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<vector<int>>& res){
    for(auto& t:res){
        cout<<t[0]<<","<<t[1]<<endl;
    }
}

class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int left = 0,right = nums.size()-1;
        vector<vector<int>>res;
        while(left<right){
            int sum = nums[left]+nums[right];
            if(sum==target){
                res.push_back({nums[left],nums[right]});
                left++;
                right--;
            }else if(sum>target){
                right--;
            }else{
                left++;
            }
        }
        return res;
    }
};

int main(){
    Solution s = Solution();
    vector<int> nums = {5,6,5,6};
    int target = 11;
    vector<vector<int>> res = s.pairSums(nums,target);
    print(res);
    return 0;
}