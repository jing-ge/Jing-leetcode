// 面试题 16.21. Sum Swap LCCI
// Given two arrays of integers, find a pair of values (one value from each array) that you can swap to give the two arrays the same sum.

// Return an array, where the first element is the element in the first array that will be swapped, and the second element is another one in the second array. If there are more than one answers, return any one of them. If there is no answer, return an empty array.

// Example:

// Input: array1 = [4, 1, 2, 1, 1, 2], array2 = [3, 6, 3, 3]
// Output: [1, 3]
// Example:

// Input: array1 = [1, 2, 3], array2 = [4, 5, 6]
// Output: []
// Note:

// 1 <= array1.length, array2.length <= 100000
// 通过次数5,618提交次数12,491
#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        vector<int>res;
        int dif = accumulate(array1.begin(), array1.end(), 0) - accumulate(array2.begin(), array2.end(), 0);
        if(dif&1)return {};
        unordered_set<int> s(array1.begin(),array1.end());
        dif >>=1;
        for(int i:array2){
            if(s.count(i+dif))return {i+dif,i};
        }
        return {};
    }
};

int main(){
    Solution s = Solution();
    vector<int> array1 = {4, 1, 2, 1, 1, 2},array2 = {3, 6, 3, 3};
    vector<int> res = s.findSwapValues(array1,array2);
    cout<<res[0]<<","<<res[1]<<endl;
    return 0;
}