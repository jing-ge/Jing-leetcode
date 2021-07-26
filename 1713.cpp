// 1713. Minimum Operations to Make a Subsequence
// You are given an array target that consists of distinct integers and another integer array arr that can have duplicates.

// In one operation, you can insert any integer at any position in arr. For example, if arr = [1,4,1,2], you can add 3 in the middle and make it [1,4,3,1,2]. Note that you can insert the integer at the very beginning or end of the array.

// Return the minimum number of operations needed to make target a subsequence of arr.

// A subsequence of an array is a new array generated from the original array by deleting some elements (possibly none) without changing the remaining elements' relative order. For example, [2,7,4] is a subsequence of [4,2,3,7,2,1,4] (the underlined elements), while [2,4,2] is not.

 

// Example 1:

// Input: target = [5,1,3], arr = [9,4,2,3,4]
// Output: 2
// Explanation: You can add 5 and 1 in such a way that makes arr = [5,9,4,1,2,3,4], then target will be a subsequence of arr.
// Example 2:

// Input: target = [6,4,8,1,3,2], arr = [4,7,6,2,3,8,6,1]
// Output: 3
 

// Constraints:

// 1 <= target.length, arr.length <= 105
// 1 <= target[i], arr[i] <= 109
// target contains no duplicates.
// 通过次数6,729提交次数14,002

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> map;
        for(int i=0;i<target.size();i++){
            map[target[i]] = i;
        }
        vector<int>d;
        for(int i=0;i<arr.size();i++){
            if(map.count(arr[i])){
                int t = map[arr[i]];
                auto it = lower_bound(d.begin(),d.end(),t);
                if(it!=d.end()){
                    *it = t;
                }else{
                    d.push_back(t);
                }
            }
        }
        return target.size()-d.size();
    }
};

int main(){
    Solution s;
    vector<int> target = {5,1,3},arr = {9,4,2,3,4};
    int res = s.minOperations(target,arr);
    cout<<res<<endl;
    return 0;
}