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
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>cur;
        backtrace(cur,nums);
        return res;
    }

    void backtrace(vector<int>&cur,vector<int>&nums){
        if(cur.size()==nums.size()){
            res.push_back(cur);
            return;
        }
        for(int i:nums){
            if(find(cur.begin(),cur.end(),i)!=cur.end())continue;
            cur.push_back(i);
            backtrace(cur,nums);
            cur.pop_back();
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