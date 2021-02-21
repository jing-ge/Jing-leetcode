// 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
// Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

 

// Example 1:

// Input: nums = [8,2,4,7], limit = 4
// Output: 2 
// Explanation: All subarrays are: 
// [8] with maximum absolute diff |8-8| = 0 <= 4.
// [8,2] with maximum absolute diff |8-2| = 6 > 4. 
// [8,2,4] with maximum absolute diff |8-2| = 6 > 4.
// [8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
// [2] with maximum absolute diff |2-2| = 0 <= 4.
// [2,4] with maximum absolute diff |2-4| = 2 <= 4.
// [2,4,7] with maximum absolute diff |2-7| = 5 > 4.
// [4] with maximum absolute diff |4-4| = 0 <= 4.
// [4,7] with maximum absolute diff |4-7| = 3 <= 4.
// [7] with maximum absolute diff |7-7| = 0 <= 4. 
// Therefore, the size of the longest subarray is 2.
// Example 2:

// Input: nums = [10,1,2,4,7,2], limit = 5
// Output: 4 
// Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
// Example 3:

// Input: nums = [4,2,2,2,4,4,2,2], limit = 0
// Output: 3
 

// Constraints:

// 1 <= nums.length <= 10^5
// 1 <= nums[i] <= 10^9
// 0 <= limit <= 10^9
// 通过次数10,869提交次数25,815

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    int longestSubarray1(vector<int>& nums, int limit) {
        multiset<int> s;
        int n = nums.size();
        int l = 0,r = 0, res = 0;
        while(r<n){
            s.insert(nums[r]);
            while(*s.rbegin()-*s.begin() > limit){
                s.erase(s.find(nums[l]));
                l++;
            }
            res = max(res, r-l+1);
            r++;
        }
        return res;
    }
    int longestSubarray(vector<int>& nums, int limit) {
        map<int,int> m;
        int n = nums.size();
        int l = 0,r = 0, res = 0;
        while(r<n){
            m[nums[r]]++;
            while(m.rbegin()->first-m.begin()->first > limit){
                m[nums[l]]--;
                if(m[nums[l]]==0){
                    m.erase(nums[l]);
                }
                l++;
            }
            res = max(res, r-l+1);
            r++;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {10,1,2,4,7,2};
    int limit = 5;
    int res = s.longestSubarray(nums,limit);
    cout<<res<<endl;
    return 0;
}