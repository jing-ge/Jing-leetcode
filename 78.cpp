// 78. Subsets
// Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]
 

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// All the numbers of nums are unique.
// 通过次数210,217提交次数263,950

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    vector<vector<int>> subsets(vector<int>& nums) {
        res.push_back({});
        backtrace(nums,0);
        return res;
    }
    void backtrace(vector<int> &nums,int idx){
        for(int i=idx;i<nums.size();i++){
            // cout<<i<<endl;
            tmp.push_back(nums[i]);
            res.push_back(tmp);
            backtrace(nums,i+1);
            tmp.pop_back();
        }
    }
};

int main(){
    vector<int> nums = {1,2,3};
    Solution s;
    vector<vector<int>> res = s.subsets(nums);
    for (auto t:res){
        for(int i:t)cout<<i<<",";
        cout<<endl;
    }
    return 0;
}