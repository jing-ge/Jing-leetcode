// 面试题 16.16. Sub Sort LCCI
// Given an array of integers, write a method to find indices m and n such that if you sorted elements m through n, the entire array would be sorted. Minimize n - m (that is, find the smallest such sequence).

// Return [m,n]. If there are no such m and n (e.g. the array is already sorted), return [-1, -1].

// Example:

// Input:  [1,2,4,7,10,11,7,12,6,7,16,18,19]
// Output:  [3,9]
// Note:

// 0 <= len(array) <= 1000000
// 通过次数9,000提交次数20,623
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        if(array.empty())return {-1,-1};
        int m=0,n=array.size()-1;
        vector<int>temp(array);
        sort(temp.begin(),temp.end());
        for(;m<array.size();m++){
            if(array[m]!=temp[m])break;
        }
        for(;n>=0;n--){
            if(array[n]!=temp[n])break;
        }
        if(m>n)m=-1;
        return {m,n};
    }
    vector<int> subSort2(vector<int>& array) {
        if(array.empty())return {-1,-1};
        int first = -1,last = -1;
        int MIN = INT32_MAX,MAX = INT32_MIN;
        int len = array.size();
        for(int i=0;i<len;i++){
            if(array[i]<MAX){
                last = i;
            }else{
                MAX = max(MAX,array[i]);
            }
            if(array[len-i-1]>MIN){
                first = len-i-1;
            }else{
                MIN = min(MIN,array[len-i-1]);
            }
            // cout<<first<<","<<last<<endl;
        }
        return {first,last};
    }
};

int main(){
    Solution s = Solution();
    vector<int> nums = {1,2,4,7,10,11,7,12,6,7,16,18,19};
    vector<int>res = s.subSort2(nums);
    cout<<res[0]<<","<<res[1]<<endl;
    return 0;
}