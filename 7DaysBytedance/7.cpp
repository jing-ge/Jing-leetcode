//leetcode 1675
// 1675. Minimize Deviation in Array
// You are given an array nums of n positive integers.

// You can perform two types of operations on any element of the array any number of times:

// If the element is even, divide it by 2.
// For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
// If the element is odd, multiply it by 2.
// For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].
// The deviation of the array is the maximum difference between any two elements in the array.

// Return the minimum deviation the array can have after performing some number of operations.

 

// Example 1:

// Input: nums = [1,2,3,4]
// Output: 1
// Explanation: You can transform the array to [1,2,3,2], then to [2,2,3,2], then the deviation will be 3 - 2 = 1.
// Example 2:

// Input: nums = [4,1,5,20,3]
// Output: 3
// Explanation: You can transform the array after two operations to [4,2,5,5,3], then the deviation will be 5 - 2 = 3.
// Example 3:

// Input: nums = [2,10,8]
// Output: 3
 

// Constraints:

// n == nums.length
// 2 <= n <= 105
// 1 <= nums[i] <= 109
// 通过次数1,432提交次数3,373
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void print(vector<int> &temp){
    for(int t:temp){
        cout<<t<<",";
    }
    cout<<endl;
}

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size(),n_max =INT32_MIN,res = INT32_MAX;
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i=0;i<n;i++){
            while(!(nums[i]&1))nums[i]/=2;
            q.push(nums[i]);
            n_max = max(n_max,nums[i]);
        }
        while(1){
            int t =q.top();
            q.pop();
            res = min(res,n_max-t);
            if(!(t&1))break;
            n_max = max(n_max,t<<1);
            q.push(t<<1);
        }
        return res;
    }
    int minimumDeviation1(vector<int>& nums) {
        int n = nums.size(),n_min =INT32_MAX,res = INT32_MAX;
        priority_queue<int> q;
        for(int i=0;i<n;i++){
            if(nums[i]&1)nums[i]*=2;
            q.push(nums[i]);
            n_min = min(n_min,nums[i]);
        }
        while(1){
            int t = q.top();
            q.pop();
            res = min(res, t-n_min);
            if(t&1)break;
            n_min = min(n_min,t>>1);
            q.push(t>>1);
        }
        return res;
    }

};

int main(){
    vector<int> nums = {3,5};
    Solution s;
    int res = s.minimumDeviation(nums);
    cout<<res<<endl;
    return 0;
}