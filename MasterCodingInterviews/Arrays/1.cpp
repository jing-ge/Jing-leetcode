// Given an array of integers ,return the indices of the 
// two numbers that add up to a given targe.

// examples:
// arr = [1,3,7,9,2]
// target = 11

// step 1: no negative number ; no duplicate number, have a solusion or not

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target)return{i,j};
            }
        }
        return {};
    }
    vector<int> twoSum2(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])==mp.end()){
                mp[target-nums[i]] = i;
            }else{
                return {mp[nums[i]],i};
            }
        }
    }
};

int main(){
    vector<int> nums = {1,3,7,9,2};
    int target = 11;
    Solution s;
    vector<int> res = s.twoSum2(nums,target);
    cout<<res[0]<<","<<res[1]<<endl;
    return 0;
}