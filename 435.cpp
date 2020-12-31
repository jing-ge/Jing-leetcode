// 435. Non-overlapping Intervals
// Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

// Example 1:

// Input: [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
// Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
// Example 2:

// Input: [[1,2],[1,2],[1,2]]
// Output: 2
// Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
// Example 3:

// Input: [[1,2],[2,3]]
// Output: 0
// Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 

// Note:

// You may assume the interval's end point is always bigger than its start point.
// Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
// 通过次数36,027提交次数76,529

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<vector<int>>&res){
    for(auto&t :res){
        cout<<t[0]<<","<<t[1]<<endl;
    }
    cout<<"------------"<<endl;;
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==0)return 0;
        sort(intervals.begin(),intervals.end(),[](vector<int>& a, vector<int>& b) {
            // if(a[1]<b[1])return true;
            // else if(a[1]==b[1]){
            //     return a[0]<b[0];
            // }else{
            //     return false;
            // }
            return a[1]<b[1];
        });
        int res = 1;
        int end = intervals[0][1];
        for(auto &t:intervals){
            int start = t[0];
            if(start>=end){
                res++;
                end = t[1];
            }
        }
        return intervals.size() - res;
    }
};

int main(){
    Solution s = Solution();
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    int res = s.eraseOverlapIntervals(intervals );
    cout<<res<<endl;
    return 0;
}