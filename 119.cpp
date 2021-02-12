// 119. Pascal's Triangle II
// Given an integer rowIndex, return the rowIndexth row of the Pascal's triangle.

// Notice that the row index starts from 0.


// In Pascal's triangle, each number is the sum of the two numbers directly above it.

// Follow up:

// Could you optimize your algorithm to use only O(k) extra space?

 

// Example 1:

// Input: rowIndex = 3
// Output: [1,3,3,1]
// Example 2:

// Input: rowIndex = 0
// Output: [1]
// Example 3:

// Input: rowIndex = 1
// Output: [1,1]
 

// Constraints:

// 0 <= rowIndex <= 33
// 通过次数99,747提交次数154,511

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        int nums = 1;
        for(int i=0;i<=rowIndex;i++){
            res.push_back(nums);
            nums = nums*(rowIndex-i)/(i+1);
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 3;
    vector<int> nums = s.getRow(n);
    for(int &i:nums)cout<<i<<",";
    cout<<endl;
    return 0;
}