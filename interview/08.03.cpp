// 面试题 08.03. Magic Index LCCI
// A magic index in an array A[0...n-1] is defined to be an index such that A[i] = i. Given a sorted array of integers, write a method to find a magic index, if one exists, in array A. If not, return -1. If there are more than one magic index, return the smallest one.

// Example1:

//  Input: nums = [0, 2, 3, 4, 5]
//  Output: 0
// Example2:

//  Input: nums = [1, 1, 1]
//  Output: 1
// Note:

// 1 <= nums.length <= 1000000
// This problem is the follow-up of the original problem in the book, i.e. the values are not distinct.

#include <iostream>
#include <vector> 

using namespace std;

class Solution {
public:
    int findMagicIndex2(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==i)return i;
        }
        return -1;
    }
    int findMagicIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==i)return i;
            if(nums[i]>i)i = nums[i]-1;
        }
        return -1;
    }
    int findMagicIndex3(vector<int>& nums) {
        return bnasearch(nums,0,nums.size()-1);
    }
    int bnasearch(vector<int>&nums,int start,int end){
        if(start>end)return -1;
        int mid = start+(end-start)/2;
        int res = bnasearch(nums,start,mid-1);
        if(res!=-1)return res;
        else if(nums[mid]==mid)return mid;
        else return bnasearch(nums,mid+1,end);
    }
};

int main(){
    vector<int> nums = {1,1,1};
    Solution s = Solution();
    int i = s.findMagicIndex3(nums);
    cout<<i<<endl;
    return 0;
}