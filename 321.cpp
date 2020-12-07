// 321. Create Maximum Number
// Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the k digits.

// Note: You should try to optimize your time and space complexity.

// Example 1:

// Input:
// nums1 = [3, 4, 6, 5]
// nums2 = [9, 1, 2, 5, 8, 3]
// k = 5
// Output:
// [9, 8, 6, 5, 3]
// Example 2:

// Input:
// nums1 = [6, 7]
// nums2 = [6, 0, 4]
// k = 5
// Output:
// [6, 7, 6, 0, 4]
// Example 3:

// Input:
// nums1 = [3, 9]
// nums2 = [8, 9]
// k = 3
// Output:
// [9, 8, 9]

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(),n = nums2.size();
        vector<int> Max(k,0);
        int start = max(0, k-n),end = min(k,m);//?
        for(int i = start; i<=end;i++){
            cout<<"----------------"<<endl;
            vector<int> subsequence1(maxSubsequence(nums1,i));
            vector<int> subsequence2(maxSubsequence(nums2,k-i));
            cout<<"array 1:"<<i<<endl;
            print(subsequence1);
            cout<<"array 2:"<<k-i<<endl;
            print(subsequence2);
            cout<<"merge:"<<endl;
            vector<int> curMax(merge(subsequence1,subsequence2));
            print(curMax);
            if (compare(curMax,0,Max,0)>0){
                Max.swap(curMax);
            }
            cout<<"Max:"<<endl;
            print(Max);
            cout<<"----------------"<<endl;
        }
        return Max;
    }

    vector<int> maxSubsequence(vector<int>& nums,int k){
        vector<int> stack(k,0);
        int top = -1;
        int remain = nums.size() -k;
        for (int i=0;i<nums.size();i++) {
            int num = nums[i]; 
            while (top >= 0 && stack[top] < num && remain > 0) {
                top--;
                remain--;
            }
            if (top < k - 1) {
                stack[++top] = num;
            } else {
                remain--;
            }
        }
        return stack;
    }

    vector<int> merge(vector<int>& subsequence1,vector<int> subsequence2) {
        int x = subsequence1.size(),y = subsequence2.size();
        if(x == 0){
            return subsequence2;
        }
        if (y==0){
            return subsequence1;
        }
        int length = x+y;
        vector<int> res(length,0);
        int idx1 = 0,idx2 = 0;
        for(int i = 0;i<length;i++){
            if(compare(subsequence1,idx1,subsequence2,idx2)>0){
                res[i] = subsequence1[idx1];
                idx1++;
            }else{
                res[i] = subsequence2[idx2];
                idx2++;
            }
        }
        return res;
    }

    int compare(vector<int> & a, int idx1, vector<int> &b, int idx2){
       int x = a.size(),y = b.size();
       while(idx1<x&&idx2<y){
           int dif = a[idx1] - b[idx2];
           if(dif!=0){
               return dif;
           }
           idx1++;
           idx2++;
       }
       return (x-idx1)-(y-idx2);
    }
    void print(vector<int> & nums){
        for(int i :nums) {
            cout<<i<<",";
        }
        cout<<endl;
    }
};

int main()
{
    Solution s = Solution();
    vector<int> nums1 = {2,5,6,4,4,0};
    vector<int> nums2 = {7,3,8,0,6,5,7,6,2};
    int k = 15;
    // vector<int> nums1 = {6,7};
    // vector<int> nums2 = {6,0,4};
    // int k = 5;
// [2,5,6,4,4,0]
// [7,3,8,0,6,5,7,6,2]
// 15
    
    vector<int>res = s.maxNumber(nums1, nums2,k);
    // vector<int>res = s.merge(nums1,nums2);
    // vector<int>res = s.maxSubsequence(nums2, 3);
    cout<<"-------------"<<endl;
    for(int i :res){
        cout<<i;
    }
    cout<<endl;
}