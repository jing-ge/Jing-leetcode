// 面试题 17.19. Missing Two LCCI
// You are given an array with all the numbers from 1 to N appearing exactly once, except for two number that is missing. How can you find the missing number in O(N) time and 0(1) space?

// You can return the missing numbers in any order.

// Example 1:

// Input: [1]
// Output: [2,3]
// Example 2:

// Input: [2,3]
// Output: [1,4]
// Note:

// nums.length <= 30000
// 通过次数5,352提交次数9,299

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> missingTwo1(vector<int>& nums) {
        //复杂度 时间O(nlogn) 空间O(1)
        int t=1;
        vector<int>res;
        int i=0;
        sort(nums.begin(),nums.end());
        while(i<nums.size()){
            if(nums[i]==t){
                t++;
                i++;
            }else{
                res.push_back(t);
                t++;
            }
        }
        while(res.size()<2){
            res.push_back(t);t++;
        }
        return res;
    }
    //求和 复杂度 时间O(n) 空间O(1)
    vector<int> missingTwo2(vector<int>& nums) {
        int n = nums.size()+2;
        int sum = n*(n+1)/2;
        for(int &x:nums)sum-=x;
        int limit = sum/2;
        int one=0;
        for(int &x:nums){
            if(x<=limit)one+=x;
        }
        one = limit*(limit+1)/2 - one;
        return {one,sum-one};
    }
    //异或 复杂度 时间O(n) 空间O(1)
    vector<int> missingTwo3(vector<int>& nums) {
        int n = nums.size()+2;
        int sum = n*(n+1)/2;
        for(int &x:nums)sum-=x;
        int div = sum/2;
        int a = 0,b = 0;
        for(int &x:nums){
            if(x<=div){
                a^=x;
            }else{
                b^=x;
            }
        }
        for(int i=1;i<=n;i++){
            if(i<=div)a^=i;
            else b^=i;
        }
        return {a,b};
    }
    //hash
    vector<int> missingTwo4(vector<int>& nums) {
        nums.push_back(-1);
        nums.push_back(-1);
        nums.push_back(-1);
        for(int i=0;i<nums.size();i++){
            while(nums[i]!=i&&nums[i]!=-1){
                swap(nums[i],nums[nums[i]]);
            }
        }
        vector<int>res;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==-1)res.push_back(i);
        }
        return res;
    }
};

int main(){
    Solution s = Solution();
    vector<int> nums = {2,3};
    vector<int> res = s.missingTwo3(nums);
    cout<<res[0]<<","<<res[1]<<endl;
    return 0;
}