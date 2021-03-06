// 503. Next Greater Element II
// Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

// Example 1:
// Input: [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2; 
// The number 2 can't find next greater number; 
// The second 1's next greater number needs to search circularly, which is also 2.
// Note: The length of given array won't exceed 10000.

// 通过次数64,364提交次数105,115

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    //暴力解法
    vector<int> nextGreaterElements1(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            res.push_back(get(nums,i));
        }
        // get(nums,1);
        return res;
    }
    int get(vector<int> &nums,int idx){
        cout<<idx<<endl;
        int t = nums[idx];
        int q = idx+1;
        for(int i=0;i<nums.size();i++){
            if(q==idx)return -1;
            if(q==nums.size()){q = 0;continue;}
            if(nums[q]>t)return nums[q];
            q++;
        }
        return -1;
    }
    vector<int> nextGreaterElements(vector<int>& nums){
        stack<int>s;
        int n = nums.size();
        vector<int> res(n,-1);
        for(int i=0;i<2*n-1;i++){
            while(!s.empty()&&nums[s.top()]<nums[i%n]){
                res[s.top()] = nums[i%n];
                s.pop();
            }
            s.push(i%n);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,1};
    vector<int> res = s.nextGreaterElements(nums);
    for(int i:res)cout<<i<<",";
    cout<<endl;
    return 0;
}