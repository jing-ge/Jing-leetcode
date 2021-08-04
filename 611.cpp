// 611. Valid Triangle Number
// Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

 

// Example 1:

// Input: nums = [2,2,3,4]
// Output: 3
// Explanation: Valid combinations are: 
// 2,3,4 (using the first 2)
// 2,3,4 (using the second 2)
// 2,2,3
// Example 2:

// Input: nums = [4,2,3,4]
// Output: 4
 

// Constraints:

// 1 <= nums.length <= 1000
// 0 <= nums[i] <= 1000
// 通过次数23,174提交次数45,559

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int triangleNumber1(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    if(nums[i]+nums[j]>nums[k])res++;
                    else break;
                }
            }
        }
        return res;
    }
    int triangleNumber2(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int l = j+1,r = nums.size()-1,k = j;
                while (l<=r)
                {
                    int mid = (l+r)/2;
                    if(nums[mid]<nums[i]+nums[j]){
                        k = mid;
                        l = mid+1;
                    }else{
                        r = mid-1;
                    }  
                }
                res+=k-j;
            }
        }
        return res;
    }
    int triangleNumber(vector<int>& nums) {
        int res = 0,n = nums.size();
        if(n<3)return 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            int j = i+1,k =j;
            while (j<n)
            {
                while (k+1<n&&nums[i]+nums[j]>nums[k+1])
                {
                    k++;
                }
                res+=max(k-j,0);
                // cout<<i<<","<<j<<","<<k<<endl;
                // cout<<res<<endl;
                j++;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {4,2,3,4};
    int res = s.triangleNumber(nums);
    cout<<res<<endl;
    return 0;
}