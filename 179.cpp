// 179. Largest Number
// Given a list of non-negative integers nums, arrange them such that they form the largest number.

// Note: The result may be very large, so you need to return a string instead of an integer.

 

// Example 1:

// Input: nums = [10,2]
// Output: "210"
// Example 2:

// Input: nums = [3,30,34,5,9]
// Output: "9534330"
// Example 3:

// Input: nums = [1]
// Output: "1"
// Example 4:

// Input: nums = [10]
// Output: "10"
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 109
// 通过次数51,412提交次数136,021
#include <iostream>
#include <vector>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        if(nums.size()==1)return to_string(nums[0]);
        for(int i:nums){
            temp.push_back(to_string(i));
        }
        sort(temp.begin(),temp.end(),[](string &a, string &b)->bool{
            return a+b>b+a;
        });
        if(temp[temp.size()-1]=="0"&&temp[0]=="0")return "0";
        string res;
        for(auto &t:temp){
            res+=t;
        }
        return res;
    }
};

int main(){
    vector<int> nums = {3,30,34,5,9};
    Solution s;
    string res = s.largestNumber(nums);
    cout<<res<<endl;
    return 0;
}