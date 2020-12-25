// 面试题 10.03. Search Rotate Array LCCIGiven a sorted array of n integers that has been rotated an unknown number of times, write code to find an element in the array. You may assume that the array was originally sorted in increasing order. If there are more than one target elements in the array, return the smallest index.

// Example1:

//  Input: arr = [15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14], target = 5
//  Output: 8 (the index of 5 in the array)
// Example2:

//  Input: arr = [15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14], target = 11
//  Output: -1 (not found)
// Note:

// 1 <= arr.length <= 1000000
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int i=1;
        for(;i<arr.size();i++){
            if(arr[i]<arr[i-1])break;
        }
        int l = binsearch(arr,0,i-1,target);
        int r = binsearch(arr,i,arr.size()-1,target);
        if(l!=-1)return l;
        if(r!=-1)return r;
        return -1;
    }
    int binsearch(vector<int>& arr,int left,int right,int target){
        int l = left,r = right;
        while (l<=r)
        {
            int mid = l+(r-l)/2;
            if(arr[mid]>=target){
                r = mid-1;
            }else if(arr[mid]<target){
                l = mid+1;
            }
        }
        if(l>right||arr[l]!=target)return -1;
        return l;
    }
};

int main(){
    vector<int> arr = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    int target = 11;
    Solution s = Solution();
    int res = s.search(arr,target);
    cout<<res<<endl;
    return 0;
}