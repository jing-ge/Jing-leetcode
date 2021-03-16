// 46. PermutationsGiven an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

//  

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<vector<int>> res){
    for(auto i:res){
        for(int j:i){
            cout<<j<<",";
        }
        cout<<endl;
    }
}

class Solution {
public:
    vector<vector<int>>res;
    vector<int> tmp,status;
    vector<vector<int>> permute(vector<int>& nums) {
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
            if(status[i]==0){
                tmp.push_back(nums[i]);
                status[i] = 1;
                backtrack(nums);
                status[i] = 0;
                tmp.pop_back();
            }
        }
    }
    void backtrack2(vector<int>& nums,int idx){
        if(idx==nums.size()){
            res.push_back(nums);
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            backtrack2(nums,idx+1);
            swap(nums[i],nums[idx]);
        }
    }
};

int main(){
    vector<int> nums = {1,2,3};
    Solution s = Solution();
    vector<vector<int>> res = s.permute(nums);
    print(res);
    return 0;
}