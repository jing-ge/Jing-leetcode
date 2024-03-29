// 1893. Check if All the Integers in a Range Are Covered
// You are given a 2D integer array ranges and two integers left and right. Each ranges[i] = [starti, endi] represents an inclusive interval between starti and endi.

// Return true if each integer in the inclusive range [left, right] is covered by at least one interval in ranges. Return false otherwise.

// An integer x is covered by an interval ranges[i] = [starti, endi] if starti <= x <= endi.

 

// Example 1:

// Input: ranges = [[1,2],[3,4],[5,6]], left = 2, right = 5
// Output: true
// Explanation: Every integer between 2 and 5 is covered:
// - 2 is covered by the first range.
// - 3 and 4 are covered by the second range.
// - 5 is covered by the third range.
// Example 2:

// Input: ranges = [[1,10],[10,20]], left = 21, right = 21
// Output: false
// Explanation: 21 is not covered by any range.
 

// Constraints:

// 1 <= ranges.length <= 50
// 1 <= starti <= endi <= 50
// 1 <= left <= right <= 50
// 通过次数14,384提交次数24,394

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
// 给你一个二维整数数组 ranges 和两个整数 left 和 right 。每个 ranges[i] = [starti, endi] 表示一个从 starti 到 endi 的 闭区间 。

// 如果闭区间 [left, right] 内每个整数都被 ranges 中 至少一个 区间覆盖，那么请你返回 true ，否则返回 false 。

// 已知区间 ranges[i] = [starti, endi] ，如果整数 x 满足 starti <= x <= endi ，那么我们称整数x 被覆盖了。

//  

// 示例 1：

// 输入：ranges = [[1,2],[3,4],[5,6]], left = 2, right = 5
// 输出：true
// 解释：2 到 5 的每个整数都被覆盖了：
// - 2 被第一个区间覆盖。
// - 3 和 4 被第二个区间覆盖。
// - 5 被第三个区间覆盖。
// 示例 2：

// 输入：ranges = [[1,10],[10,20]], left = 21, right = 21
// 输出：false
// 解释：21 没有被任何一个区间覆盖。
//  

// 提示：

// 1 <= ranges.length <= 50
// 1 <= starti <= endi <= 50
// 1 <= left <= right <= 50

class Solution {
public:
    bool isCovered_(vector<vector<int>>& ranges, int left, int right) {
        unordered_map<int,int> map;
        for(auto t:ranges){
            for(int i =t[0];i<=t[1];i++){
                map[i]++;
            }
        }
        for(int i=left;i<=right;i++){
            if(map[i]==0)return false;
        }
        return true;
    }
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> vec(52);
        for(auto &t:ranges){
            vec[t[0]]++;
            vec[t[1]+1]--;
        }
        int curr = 0;
        for(int i=1;i<vec.size();i++){
            curr+=vec[i];
            if(i>=left&&i<=right&&curr<=0)return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    vector<vector<int>> ranges = {{1,2},{3,4},{5,6}};
    int left=2,right = 5;
    bool res = s.isCovered(ranges,left,right);
    cout<<res<<endl;
    return 0;
}