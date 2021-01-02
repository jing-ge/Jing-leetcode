// 面试题 16.17. Contiguous Sequence LCCI
// You are given an array of integers (both positive and negative). Find the contiguous sequence with the largest sum. Return the sum.

// Example:

// Input:  [-2,1,-3,4,-1,2,1,-5,4]
// Output:  6
// Explanation:  [4,-1,2,1] has the largest sum 6.
// Follow Up:

// If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

// 通过次数21,584提交次数36,449

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())return 0;
        int res = nums[0];
        vector<int>dp(nums.size(),0);
        dp[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            dp[i] = max(dp[i-1]+nums[i],nums[i]);
            res = max(res,dp[i]);
        }
        return res;
    }
    int maxSubArray2(vector<int>& nums) {
        if(nums.empty())return 0;
        return dc(nums,0,nums.size()-1);
    }
    int dc(vector<int>& nums,int i,int j){
        if(i==j)return nums[i];
        int mid = i + (j-i)/2;
        int left = dc(nums,i,mid);
        int right = dc(nums,mid+1,j);
        int leftsum = 0,maxleft =INT32_MIN;
        for(int t=mid;t>=i;t--){
            leftsum += nums[t];
            maxleft = max(maxleft,leftsum);
        }
        int rightsum = 0,maxright =INT32_MIN;
        for(int t=mid+1;t<=j;t++){
            rightsum += nums[t];
            maxright = max(maxright,rightsum);
        }
        return max(max(left,right),maxleft+maxright);
    }
};

int main(){
    vector<int>nums ={-2,1,-3,4,-1,2,1,-5,4};
    Solution s = Solution();
    int res = s.maxSubArray2(nums);
    cout<<res<<endl; 
    return 0;

}