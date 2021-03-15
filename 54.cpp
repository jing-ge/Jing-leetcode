// 54. Spiral Matrix
// Given an m x n matrix, return all elements of the matrix in spiral order.

 

// Example 1:


// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:


// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100
// 通过次数112,382提交次数256,522

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty())return res;
        int u = 0;
        int d = matrix.size()-1;
        int l = 0;
        int r = matrix[0].size()-1;
        while(true){
            for(int i=l;i<=r;i++){
                res.push_back(matrix[u][i]);
            }
            u++;
            cout<<u<<","<<d<<","<<l<<","<<r<<endl;
            if(u>d)break;
            for(int i=u;i<=d;i++){
                res.push_back(matrix[i][r]);
            }
            r--;
            cout<<u<<","<<d<<","<<l<<","<<r<<endl;

            if(r<l)break;
            for(int i=r;i>=l;i--){
                res.push_back(matrix[d][i]);
            }
            d--;
            cout<<u<<","<<d<<","<<l<<","<<r<<endl;
            if(d<u)break;
            for(int i=d;i>=u;i--){
                res.push_back(matrix[i][l]);
            }
            l++;
            cout<<u<<","<<d<<","<<l<<","<<r<<endl;
            if(l>r)break;
        }
        return res;
    }
};

int main(){
    vector<vector<int>> matrix = {{2,5,8},{4,0,-1}};
    Solution s;
    vector<int> res = s.spiralOrder(matrix);
    for(int i:res)cout<<i<<",";
    cout<<endl;
}