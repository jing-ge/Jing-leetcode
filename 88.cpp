// 88. Merge Sorted Array
// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

// Note:

// The number of elements initialized in nums1 and nums2 are m and n respectively.
// You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2.
// Example:

// Input:
// nums1 = [1,2,3,0,0,0], m = 3
// nums2 = [2,5,6],       n = 3

// Output: [1,2,2,3,5,6]

#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &data){
    for(int i=0;i<data.size();i++){
        cout<<data[i]<<",";
    }
    cout<<endl;
}

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m==0){
            for(int i=0;i<nums2.size();i++){
                nums1[i] = nums2[i];
            }
        }
        if(n==0)return;
        for(int i=m-1;i>=0;i--){
            nums1[i+n] = nums1[i];
        }
        int i = n;
        int j = 0;
        int t = 0;
        while(i<m+n&&j<n){
            if(nums1[i]<nums2[j]){
                nums1[t] = nums1[i];
                i++;
            }else{
                nums1[t] = nums2[j];
                j++;
            }
            t++;
            cout<<"i="<<i<<",j="<<j<<",t="<<t<<endl;
            print(nums1);
        }
        if(i==m+n){
            while(j<n){
                nums1[t] = nums2[j];
                j++;
                t++;
            }
        }
    }
};

int main(){
    vector<int> nums1 = {4,0,0,0,0,0};
    int m = 1;
    vector<int> nums2 = {1,2,3,5,6};
    int n = 5;
    Solution s = Solution();
    s.merge(nums1,m,nums2,n);
    print(nums1);
    return 0;
}
