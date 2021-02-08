// 978. Longest Turbulent Subarray
// Given an integer array arr, return the length of a maximum size turbulent subarray of arr.

// A subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.

// More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be turbulent if and only if:

// For i <= k < j:
// arr[k] > arr[k + 1] when k is odd, and
// arr[k] < arr[k + 1] when k is even.
// Or, for i <= k < j:
// arr[k] > arr[k + 1] when k is even, and
// arr[k] < arr[k + 1] when k is odd.
 

// Example 1:

// Input: arr = [9,4,2,10,7,8,8,1,9]
// Output: 5
// Explanation: arr[1] > arr[2] < arr[3] > arr[4] < arr[5]
// Example 2:

// Input: arr = [4,8,12,16]
// Output: 2
// Example 3:

// Input: arr = [100]
// Output: 1
 

// Constraints:

// 1 <= arr.length <= 4 * 104
// 0 <= arr[i] <= 109
// 通过次数18,461提交次数41,421

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int res = 0;
        int t = 1;
        if(arr.size()<=1)return arr.size();
        if(arr.size()==2){
            if(arr[0]==arr[1])return 1;
            return 2;
        }
        bool flag = arr[0]>arr[1];
        for(int i=1;i<arr.size()-1;i++){
            if(flag){
                if(arr[i]>arr[i+1]){
                    t = 1;
                }else if(arr[i]==arr[i+1]){
                    t = 0;
                }
                else{
                    t++;
                    flag = !flag;
                }
            }else{
                if(arr[i]<arr[i+1]){
                    t = 1;
                }else if(arr[i]==arr[i+1]){
                    t = 0;
                }
                else{
                    t++;
                    flag = !flag;
                }
            }
            // cout<<t<<endl;
            res = max(res,t);
        }
        return res+1;
    }
};

int main(){
    Solution s;
    vector<int> arr = {0,1,1,0,1,0,1,1,0,0};
    int res = s.maxTurbulenceSize(arr);
    cout<<res<<endl;
    return 0;
}