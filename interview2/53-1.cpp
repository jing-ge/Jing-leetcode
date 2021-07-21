// 剑指 Offer 53 - I. 在排序数组中查找数字 I
// 统计一个数字在排序数组中出现的次数。

 

// 示例 1:

// 输入: nums = [5,7,7,8,8,10], target = 8
// 输出: 2
// 示例 2:

// 输入: nums = [5,7,7,8,8,10], target = 6
// 输出: 0
 

// 限制：

// 0 <= 数组长度 <= 50000

 

// 注意：本题与主站 34 题相同（仅返回值不同）：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/

// 通过次数136,657提交次数254,439

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int idx = bsearch(nums,target);
        int res=0;
        while (idx<nums.size()&&nums[idx]==target)
        {
            res++;idx++;
        }
        return res;
    }
    int bsearch(vector<int>& nums,int target) {
        int l = 0,r = nums.size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid]<target){
                l = mid+1;
            }else if(nums[mid]>target){
                r = mid -1;
            }else{
                r = mid - 1;
            }
        }
        return l;
    }
};

int main(){
    Solution s;
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    int res = s.search(nums,target);
    cout<<res<<endl;
    return 0;
}