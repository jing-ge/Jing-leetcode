// 面试题 17.16. The Masseuse LCCI
// A popular masseuse receives a sequence of back-to-back appointment requests and is debating which ones to accept. She needs a break between appointments and therefore she cannot accept any adjacent requests. Given a sequence of back-to-back appoint­ ment requests, find the optimal (highest total booked minutes) set the masseuse can honor. Return the number of minutes.

// Note: This problem is slightly different from the original one in the book.

 

// Example 1:

// Input:  [1,2,3,1]
// Output:  4
// Explanation:  Accept request 1 and 3, total minutes = 1 + 3 = 4
// Example 2:

// Input:  [2,7,9,3,1]
// Output:  12
// Explanation:  Accept request 1, 3 and 5, total minutes = 2 + 9 + 1 = 12
// Example 3:

// Input:  [2,1,4,5,3,1,1,3]
// Output:  12
// Explanation:  Accept request 1, 3, 5 and 8, total minutes = 2 + 4 + 3 + 3 = 12

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int massage(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        int p = nums[0];
        int q = max(nums[0],nums[1]);
        for(int i = 2;i<n;i++){
            int t = max(q,p+nums[i]);
            p = q;
            q =t;
        }
        return q;
    }
    int massage2(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        vector<int> dp(n,0);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2;i<n;i++){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};

int main(){
    Solution s= Solution();
    vector<int> nums = {2,1,4,5,3,1,1,3};
    int res = s.massage(nums);
    cout<<res<<endl;
    return 0;
}