// Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a==c and b==d), or (a==d and b==c) - that is, one domino can be rotated to be equal to another domino.

// Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].

//  

// Example 1:

// Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
// Output: 1
//  

// Constraints:

// 1 <= dominoes.length <= 40000
// 1 <= dominoes[i][j] <= 9
// 通过次数11,731提交次数23,409

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/number-of-equivalent-domino-pairs
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //O(n2)超时
    int numEquivDominoPairs1(vector<vector<int>>& dominoes) {
        int res = 0;
        for(int i=0;i<dominoes.size();i++){
            for(int j=i+1;j<dominoes.size();j++){
                if(dominoes[i][0]==dominoes[j][1]&&dominoes[i][1]==dominoes[j][0]){
                    res++;
                }
            }
        }
        return res;
    }
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int res = 0;
        vector<int> nums(100);
        for(auto &t:dominoes){
            int val = t[0]>t[1]?t[1]*10+t[0]:t[0]*10+t[1];
            res+=nums[val];
            nums[val]++;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> dominoes = {{1,2},{2,1},{3,4},{5,6}};
    int res = s.numEquivDominoPairs(dominoes);
    cout<<res<<endl;
    return 0;
}