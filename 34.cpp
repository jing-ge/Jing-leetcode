// 34. Find First and Last Position of Element in Sorted Array
// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// Follow up: Could you write an algorithm with O(log n) runtime complexity?

//  

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
// Example 3:

// Input: nums = [], target = 0
// Output: [-1,-1]
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size()==0)return {-1,-1};
        if (nums.size()==1){
            if(nums[0]==target)return{0,0};
            else return {-1,-1};
        }
        int res = binSearch(nums,target);
        // cout<<res<<endl;
        if (res==-1) {
            return {-1,-1};
        }
        int start = res;
        int end = res;
        bool lflag = true;
        bool rflag = true;
        while(lflag||rflag) {
            if (start==0) {
                lflag = false;
            }else{
                if (nums[start]==nums[start-1]) {
                    start--;
                }else{
                    lflag = false;
                }
            }
            if (end == nums.size()-1) {
                rflag = false;
            }else{
                if(nums[end]==nums[end+1]){
                    end++;
                }else{
                    rflag = false;
                }
            }
            // cout <<lflag<<","<<rflag<<endl;
        }
        return {start,end};
    }
    // int binSearch(vector<int>& nums, int target) {
    //     int start = 0;
    //     int end = nums.size()-1;
    //     if (nums[end]==target)return end;
    //     while(start<end){
    //         int mid = (start + end)/2;
    //         // cout<<start<<","<<mid<<","<<end<<endl;
    //         if (mid==start){
    //             if (nums[mid]==target){
    //                 return mid;
    //             }else{
    //                 return -1;
    //             }
    //         }
    //         if(nums[mid]==target){
    //             return mid;
    //         }else if (nums[mid]>target){
    //             end = mid;
    //         }else{
    //             start = mid;
    //         }
    //     }
    //     return -1;
    // }
    int binSearch(vector<int> nums, int target){
        int left = 0,right = nums.size()-1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid]<target){
                left = mid +1;
            } else if(nums[mid]>target){
                right = mid -1;
            }else{
                return mid;
            }
        }
        return -1;
    }

    
    int leftBound(vector<int> nums, int target){
        int left = 0,right = nums.size()-1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid]<target){
                left = mid +1;
            } else if(nums[mid]>target){
                right = mid -1;
            }else{
                right = mid-1;
            }
        }
        if (left>=nums.size()||nums[left]!=target)
            return -1;
        return left;
    }

    vector<int> lsearchRange(vector<int>& nums, int target) {
        if (nums.size()==0)return {-1,-1};
        if (nums.size()==1){
            if(nums[0]==target)return{0,0};
            else return {-1,-1};
        }
        int res = leftBound(nums,target);
        // cout<<res<<endl;
        if (res==-1) {
            return {-1,-1};
        }
        int left = res,right = res;
        while(right<nums.size()&&nums[right]==target)right++;
        return {left,right-1};
    }
};

int main()
{
    Solution s = Solution();
    vector<int> testnums = {2,2};
    int testtarget = 2;
    vector<int> output = s.searchRange(testnums, testtarget);
    cout<< output[0]<<","<<output[1]<<endl;
}