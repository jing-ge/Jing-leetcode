// 217. Contains Duplicate
// Given an array of integers, find if the array contains any duplicates.

// Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

// Example 1:

// Input: [1,2,3,1]
// Output: true
// Example 2:

// Input: [1,2,3,4]
// Output: false
// Example 3:

// Input: [1,1,1,3,3,4,3,2,4,2]
// Output: true


#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int&i:nums){
            if(m[i]>0)return true;
            m[i]++;
        }
        return false;
    }
    bool containsDuplicate1(vector<int>& nums) {
        unordered_set<int> s;
        for(int&i:nums){
            if(s.find(i)!=s.end())return true;
            s.insert(i);
        }
        return false;
    }
    bool containsDuplicate2(vector<int>& nums){
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])return true;
        }
        return false;
    }
};

int main(){
    Solution s = Solution();
    vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
    bool res = s.containsDuplicate2(nums);
    cout<<res<<endl;
    return 0;
}