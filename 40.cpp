// 40. Combination Sum II
// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

 

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]
 

// Constraints:

// 1 <= candidates.length <= 100
// 1 <= candidates[i] <= 50
// 1 <= target <= 30
// 通过次数138,785提交次数217,030

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtrace(candidates,target,0);
        return res;
    }

    void backtrace(vector<int>& nums,int target,int idx){
        if(target<0)return ;
        if(target==0){
            res.push_back(tmp);
            return ;
        }
        for(int i=idx;i<nums.size();i++){
            if(target-nums[i]<0)break;
            if(i>idx&&nums[i]==nums[i-1])continue;
            tmp.push_back(nums[i]);
            backtrace(nums,target-nums[i],i+1);
            tmp.pop_back();
        }
    } 
};

int main(){
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    Solution s;
    vector<vector<int>> res = s.combinationSum2(candidates,target);
    for (auto t:res){
        for(int i:t)cout<<i<<",";
        cout<<endl;
    }
    return 0;
}