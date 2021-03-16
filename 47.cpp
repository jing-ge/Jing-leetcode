// 47. Permutations II
// Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

// Example 1:

// Input: nums = [1,1,2]
// Output:
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]
// Example 2:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

// Constraints:

// 1 <= nums.length <= 8
// -10 <= nums[i] <= 10
// 通过次数145,971提交次数231,898

#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>>res;
    vector<int> tmp,status;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // status = vector<int> (nums.size(),0);
        // backtrack(nums);
        backtrack2(nums,0);
        return res;
    }

    void backtrack(vector<int>& nums){
        if (tmp.size() == nums.size()) {
            res.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            
            if (status[i] || (i > 0 && nums[i] == nums[i - 1] && !status[i - 1])) {
                continue;
            }
            tmp.push_back(nums[i]);
            status[i] = 1;
            backtrack(nums);
            status[i] = 0;
            tmp.pop_back();
            
        }
    }
    void backtrack2(vector<int> &nums,int idx){
        if(idx==nums.size()){
            res.push_back(nums);
            return;
        }
        set<int> st;
        for(int i=idx;i<nums.size();i++){
            if(st.find(nums[i])!=st.end())continue;
            st.insert(nums[i]);
            swap(nums[i],nums[idx]);
            backtrack2(nums,idx+1);
            swap(nums[i],nums[idx]);
        }
    }
};

int main(){
    Solution s;
    vector<int> nums = {0,0,0,1,9};
    vector<vector<int>> res = s.permuteUnique(nums);
    for (auto t:res){
        for(int i:t)cout<<i<<",";
        cout<<endl;
    }
    return 0;
}