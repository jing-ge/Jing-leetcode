// 90. Subsets II
// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]
 

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// 通过次数70,448提交次数113,803
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        backtrace(nums,0);
        return res;
    }
    void backtrace(vector<int> &nums,int idx){
        res.push_back(tmp);
        for(int i=idx;i<nums.size();i++){
            if(i>idx&&nums[i]==nums[i-1])continue;
            tmp.push_back(nums[i]);
            backtrace(nums,i+1);
            tmp.pop_back();
        }
    }

};

int main(){
    vector<int> nums = {1,2,2};
    Solution s;
    vector<vector<int>> res = s.subsetsWithDup(nums);
    for (auto t:res){
        for(int i:t)cout<<i<<",";
        cout<<endl;
    }
    return 0;
}