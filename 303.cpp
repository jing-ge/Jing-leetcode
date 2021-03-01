// 303. Range Sum Query - Immutable
// Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

// Implement the NumArray class:

// NumArray(int[] nums) Initializes the object with the integer array nums.
// int sumRange(int i, int j) Return the sum of the elements of the nums array in the range [i, j] inclusive (i.e., sum(nums[i], nums[i + 1], ... , nums[j]))
 

// Example 1:

// Input
// ["NumArray", "sumRange", "sumRange", "sumRange"]
// [[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
// Output
// [null, 1, -1, -3]

// Explanation
// NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
// numArray.sumRange(0, 2); // return 1 ((-2) + 0 + 3)
// numArray.sumRange(2, 5); // return -1 (3 + (-5) + 2 + (-1)) 
// numArray.sumRange(0, 5); // return -3 ((-2) + 0 + 3 + (-5) + 2 + (-1))
 

// Constraints:

// 0 <= nums.length <= 104
// -105 <= nums[i] <= 105
// 0 <= i <= j < nums.length
// At most 104 calls will be made to sumRange.
// 通过次数75,114提交次数112,871

#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    vector<int> data;
    NumArray(vector<int>& nums) {
        int t = 0;
        data.push_back(t);
        for(int &i:nums){
            t+=i;
            data.push_back(t);
        }
    }
    
    int sumRange(int i, int j) {
        
        return data[j+1]-data[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

int main(){
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray = NumArray(nums);
    cout<<numArray.sumRange(0, 2)<<endl; // return 1 ((-2) + 0 + 3)
    cout<<numArray.sumRange(2, 5)<<endl; // return -1 (3 + (-5) + 2 + (-1)) 
    cout<<numArray.sumRange(0, 5)<<endl; // return -3 ((-2) + 0 + 3 + (-5) + 2 + (-1))
    return 0;
}