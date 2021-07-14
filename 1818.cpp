// 1818. Minimum Absolute Sum Difference
// You are given two positive integer arrays nums1 and nums2, both of length n.

// The absolute sum difference of arrays nums1 and nums2 is defined as the sum of |nums1[i] - nums2[i]| for each 0 <= i < n (0-indexed).

// You can replace at most one element of nums1 with any other element in nums1 to minimize the absolute sum difference.

// Return the minimum absolute sum difference after replacing at most one element in the array nums1. Since the answer may be large, return it modulo 109 + 7.

// |x| is defined as:

// x if x >= 0, or
// -x if x < 0.
 

// Example 1:

// Input: nums1 = [1,7,5], nums2 = [2,3,5]
// Output: 3
// Explanation: There are two possible optimal solutions:
// - Replace the second element with the first: [1,7,5] => [1,1,5], or
// - Replace the second element with the third: [1,7,5] => [1,5,5].
// Both will yield an absolute sum difference of |1-2| + (|1-3| or |5-3|) + |5-5| = 3.
// Example 2:

// Input: nums1 = [2,4,6,8,10], nums2 = [2,4,6,8,10]
// Output: 0
// Explanation: nums1 is equal to nums2 so no replacement is needed. This will result in an 
// absolute sum difference of 0.
// Example 3:

// Input: nums1 = [1,10,4,4,2,7], nums2 = [9,3,5,1,7,4]
// Output: 20
// Explanation: Replace the first element with the second: [1,10,4,4,2,7] => [10,10,4,4,2,7].
// This yields an absolute sum difference of |10-9| + |10-3| + |4-5| + |4-1| + |2-7| + |7-4| = 20
 

// Constraints:

// n == nums1.length
// n == nums2.length
// 1 <= n <= 105
// 1 <= nums1[i], nums2[i] <= 105
// 通过次数16,098提交次数42,923

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    //错误思路
    //[1,28,21]
    // [9,21,20]
    // 输出：16
    // 预期：9
    int mod = 1000000007;
    int minAbsoluteSumDiff_(vector<int>& nums1, vector<int>& nums2) {
        int idx = 0,t = abs(nums1[0]-nums2[0]),n = nums1.size();
        for(int i=0;i<n;i++){
            int tmp = abs(nums1[i]-nums2[i]);
            if(tmp>t){
                idx = i;
                t = tmp;
            }
        }
        int idx2 = 0,t2 = abs(nums1[0]-nums2[idx]);
        for(int i=0;i<n;i++){
            int tmp = abs(nums1[0]-nums2[idx]);
            if(tmp<t2){
                idx2 = i;
                t2 = tmp;
            }
        }
        nums1[idx] = nums1[idx2];
        int res = 0;
        for(int i=0;i<n;i++){
            res = (res+abs(nums1[i]-nums2[i])) ;
        }
        return res;
    }
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<int> rec(nums1);
        sort(rec.begin(),rec.end());
        int sum = 0, maxn = 0,n = nums1.size();
        for(int i=0;i<n;i++){
            int diff = abs(nums1[i]-nums2[i]);
            sum = (sum + diff) % mod;
            int j = lower_bound(rec.begin(),rec.end(),nums2[i])-rec.begin();
            if(j<n){
                maxn = max(maxn,diff-abs(rec[j]-nums2[i]));
            }
            if(j>0){
                maxn = max(maxn,diff-abs(rec[j-1]-nums2[i]));
            }
        }
        return (sum-maxn +mod)%mod; 
    }
};

int main(){
    Solution s;
    // vector<int> nums1 = {2,4,6,8,10},nums2 = {2,4,6,8,10};
    vector<int> nums1 = {1,28,21},nums2 = {9,21,20};
    int res = s.minAbsoluteSumDiff(nums1,nums2);
    cout<<res<<endl;
    return 0;
}