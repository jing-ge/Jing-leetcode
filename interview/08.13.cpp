// 面试题 08.13. Pile Box LCCI
// You have a stack of n boxes, with widths wi, depths di, and heights hi. The boxes cannot be rotated and can only be stacked on top of one another if each box in the stack is strictly larger than the box above it in width, height, and depth. Implement a method to compute the height of the tallest possible stack. The height of a stack is the sum of the heights of each box.

// The input use [wi, di, hi] to represents each box.

// Example1:

//  Input: box = [[1, 1, 1], [2, 2, 2], [3, 3, 3]]
//  Output: 6
// Example2:

//  Input: box = [[1, 1, 1], [2, 3, 4], [2, 6, 7], [3, 4, 5]]
//  Output: 10
// Note:

// box.length <= 3000
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int pileBox(vector<vector<int>>& box) {
        int n = box.size();
        sort(box.begin(),box.end());
        vector<int>f(n+1);
        int res = 0;
        for(int i=0;i<n;i++){
            f[i] = box[i][2];
            res = max(f[i],res);
            for(int j=0;j<i;j++){
                if(box[j][0]<box[i][0]&&box[j][1]<box[i][1]&&box[j][2]<box[i][2]){
                    f[i] = max(f[i],f[j]+box[i][2]);
                    res = max(f[i],res);
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s = Solution();
    vector<vector<int>> box = {{1,1,1},{2,2,2},{3,3,3}};
    int res = s.pileBox(box);
    cout<<res<<endl;
    return 0;
}