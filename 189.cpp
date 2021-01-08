// 189. Rotate Array
// Given an array, rotate the array to the right by k steps, where k is non-negative.

// Follow up:

// Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
// Could you do it in-place with O(1) extra space?
 

// Example 1:

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
// Example 2:

// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation: 
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]
 

// Constraints:

// 1 <= nums.length <= 2 * 104
// -231 <= nums[i] <= 231 - 1
// 0 <= k <= 105

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    void rotate1(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> newArr(n);
        for (int i = 0; i < n; ++i) {
            newArr[(i + k) % n] = nums[i];
        }
        nums.assign(newArr.begin(), newArr.end());
    }
    void rotate2(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        int count = __gcd(k,n);
        for(int start = 0;start<count;start++){
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k)%n;
                swap(nums[next],prev);    
                current = next;
            }while(start!=current);

        }
    }
    void reverse(vector<int>&nums ,int start, int end){
        while(start<end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k){
        k = k%nums.size();
        reverse(nums,0,nums.size()-1);
        reverse(nums,0,k-1);
        reverse(nums,k,nums.size()-1);
    }
};

int main(){
    Solution s = Solution();
    vector<int>nums = {1,2,3,4,5,6,7};
    int k = 3;
    for(int i:nums)cout<<i<<",";
    cout<<endl;
    s.rotate(nums,k);
    for(int i:nums)cout<<i<<",";
    cout<<endl;
    return 0;
}