// 面试题 16.01. Swap Numbers LCCI
// Write a function to swap a number in place (that is, without temporary vari­ ables).

// Example:

// Input: numbers = [1,2]
// Output: [2,1]
// Note:

// numbers.length == 2

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        numbers[0] = numbers[0]^numbers[1];
        numbers[1] = numbers[1]^numbers[0];
        numbers[0] = numbers[1]^numbers[0];
        return numbers;
    }
};

int main(){
    Solution s = Solution();
    vector<int> nums = {1,2};
    vector<int>res = s.swapNumbers(nums);
    cout<<res[0]<<","<<res[1]<<endl;
    return 0;
}