#include<iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0],pre = 0;
        for(auto &t:nums){
            pre = max(pre+t,t);
            res = max(res,pre);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int res = s.maxSubArray(nums);
    cout<<res<<endl;
    return 0;
}