// 697. Degree of an Array
// Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

// Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

 

// Example 1:

// Input: nums = [1,2,2,3,1]
// Output: 2
// Explanation: 
// The input array has a degree of 2 because both elements 1 and 2 appear twice.
// Of the subarrays that have the same degree:
// [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
// The shortest length is 2. So return 2.
// Example 2:

// Input: nums = [1,2,2,3,1,4,2]
// Output: 6
// Explanation: 
// The degree is 3 because the element 2 is repeated 3 times.
// So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.
 

// Constraints:

// nums.length will be between 1 and 50,000.
// nums[i] will be an integer between 0 and 49,999.
// 通过次数37,638提交次数65,226

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int>> m;
        for(int i=0;i<nums.size();i++){
            if(m.count(nums[i])){
                m[nums[i]][1] = i;
                m[nums[i]][2]++; 
            }else{
                vector<int> t = {i,i,1};
                m[nums[i]] = t;
            }
        }
        int res = 0;
        int temp = 0;
        for(auto &t:m){
            int count = t.second[2];
            int len = t.second[1]-t.second[0]+1;
            if(t.second[2]>temp){
                temp = count;
                res = len;
            }else if(t.second[2]==temp){
                if(len<res)res = len;
            }
            cout<<t.first<<":"<<t.second[0]<<","<<t.second[1]<<","<<t.second[2]<<endl;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,2,3,1,4,2};
    int res = s.findShortestSubArray(nums);
    cout<<res<<endl;
    return 0;
}