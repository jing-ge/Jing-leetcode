// 456. 132 Pattern
// Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

// Return true if there is a 132 pattern in nums, otherwise, return false.

// Follow up: The O(n^2) is trivial, could you come up with the O(n logn) or the O(n) solution?

 

// Example 1:

// Input: nums = [1,2,3,4]
// Output: false
// Explanation: There is no 132 pattern in the sequence.
// Example 2:

// Input: nums = [3,1,4,2]
// Output: true
// Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
// Example 3:

// Input: nums = [-1,3,2,0]
// Output: true
// Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
 

// Constraints:

// n == nums.length
// 1 <= n <= 104
// -109 <= nums[i] <= 109
// 通过次数19,313提交次数64,248

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n<3)return false;
        stack<int> st;
        vector<int> mins = vector<int>(n,0);
        mins[0] = nums[0];
        for(int i=1;i<n;i++){
            mins[i] = min(mins[i-1],nums[i]);
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]==mins[i])continue;
            while(!st.empty()&&st.top()<=mins[i]){
                st.pop();
            }
            if(!st.empty()&&st.top()<nums[i]){
                return true;
            }
            st.push(nums[i]);
        }
        return false;
    }
};

int main(){
    vector<int> nums = {1,2,3,4};
    Solution s;
    bool res = s.find132pattern(nums);
    cout<<res<<endl;
    return 0;
}