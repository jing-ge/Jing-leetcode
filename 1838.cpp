#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size(),l = 0,r = 0,res = 1;
        long long total = 0;
        while (r<n)
        {
            total += (long long)(nums[r] - nums[r - 1]) * (r - l);
            while (total>k)
            {
                total -= nums[r]-nums[l];
                l++;
            }
            res = max(res,r-l+1);
            r++;
        }
        return res;
    }
};

int main(){
    vector<int> nums = {1,4,8,13};
    int k = 5;
    Solution s;
    int res = s.maxFrequency(nums,k);
    cout<<res<<endl;
    return 0;
}