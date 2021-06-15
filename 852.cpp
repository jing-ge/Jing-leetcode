// 852. Peak Index in a Mountain Array
// Let's call an array arr a mountain if the following properties hold:

// arr.length >= 3
// There exists some i with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... arr[i-1] < arr[i]
// arr[i] > arr[i+1] > ... > arr[arr.length - 1]
// Given an integer array arr that is guaranteed to be a mountain, return any i such that arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

 

// Example 1:

// Input: arr = [0,1,0]
// Output: 1
// Example 2:

// Input: arr = [0,2,1,0]
// Output: 1
// Example 3:

// Input: arr = [0,10,5,2]
// Output: 1
// Example 4:

// Input: arr = [3,4,5,1]
// Output: 2
// Example 5:

// Input: arr = [24,69,100,99,79,78,67,36,26,19]
// Output: 2

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray1(vector<int>& arr) {
        if(arr.size()<3) return 0;
        for(int i=1;i<arr.size()-1;i++){
            if(arr[i]>arr[i+1])return i;
        }
        return 0;
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0,right = arr.size()-2,res = 0;
        while (left<=right)
        {
            int mid = (left+right)/2;
            if(arr[mid]>arr[mid+1]){
                res = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> arr = {24,69,100,99,79,78,67,36,26,19};
    int res = s.peakIndexInMountainArray(arr);
    cout<<res<<endl;
    return 0;
}