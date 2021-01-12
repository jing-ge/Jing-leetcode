// 645. Set Mismatch
// The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in the set got duplicated to another number in the set, which results in repetition of one number and loss of another number.

// Given an array nums representing the data status of this set after the error. Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the form of an array.

// Example 1:
// Input: nums = [1,2,2,4]
// Output: [2,3]
// Note:
// The given array size will in the range [2, 10000].
// The given array's numbers won't have any order.
// 通过次数28,496提交次数67,034

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        if(nums.size()<2)return {};
        int res = 0;
        for(int &x:nums)res^=x;
        for(int i=1;i<=nums.size();i++)res^=i;
        int t=0;
        while(true){
            if((res>>t&1)==1)break;
            t++;
        }
        int a=0,b=0;
        for(int &x:nums){
            if((x>>t&1)==0)a^=x;
            else b^=x;
        }
        for(int x=1;x<=nums.size();x++){
            if((x>>t&1)==0)a^=x;
            else b^=x;
        }
        for(int &i:nums){
            if(i==a)return {a,b};
            else if(i==b)return {b,a};
        }
    }
};

int main(){
    vector<int> nums = {1,2,2,4};
    Solution s = Solution();
    vector<int> res = s.findErrorNums(nums);
    cout<<res[0]<<","<<res[1]<<endl;
    return 0;
}