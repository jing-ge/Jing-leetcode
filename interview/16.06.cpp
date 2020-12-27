// 面试题 16.06. Smallest Difference LCCI
// Given two arrays of integers, compute the pair of values (one value in each array) with the smallest (non-negative) difference. Return the difference.

// Example:

// Input: {1, 3, 15, 11, 2}, {23, 127, 235, 19, 8}
// Output:  3, the pair (11, 8)
// Note:

// 1 <= a.length, b.length <= 100000
// -2147483648 <= a[i], b[i] <= 2147483647
// The result is in the range [-2147483648, 2147483647]
// 通过次数7,290提交次数17,675

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int smallestDifference(vector<int>& a, vector<int>& b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int i=0,j=0;
        long res = __LONG_LONG_MAX__;
        while(i<a.size()&&j<b.size()){
            res = min(res,(long)abs(a[i]-b[j]));
            if(a[i]<b[j]){
                i++;
            }else if(a[i]>b[j]){
                j++;
            }else{
                break;
            }
        }
        return res;
    }
};

int main(){
    Solution s = Solution();
    vector<int> a = {1, 3, 15, 11, 2}, b = {23, 127, 235, 19, 8};
    int res = s.smallestDifference(a,b);
    cout<<res<<endl;
    return 0;
}