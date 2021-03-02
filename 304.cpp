// 304. Range Sum Query 2D - Immutable
// Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

// Range Sum Query 2D
// The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

// Example:
// Given matrix = [
//   [3, 0, 1, 4, 2],
//   [5, 6, 3, 2, 1],
//   [1, 2, 0, 1, 5],
//   [4, 1, 0, 1, 7],
//   [1, 0, 3, 0, 5]
// ]

// sumRegion(2, 1, 4, 3) -> 8
// sumRegion(1, 1, 2, 2) -> 11
// sumRegion(1, 2, 2, 4) -> 12
// Note:
// You may assume that the matrix does not change.
// There are many calls to sumRegion function.
// You may assume that row1 ≤ row2 and col1 ≤ col2.
// 通过次数19,948提交次数40,446

#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
    vector<vector<int>> summatrix;
    int m,n;
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        if (m==0)return;
        n = matrix[0].size();
        summatrix = vector<vector<int>>(m+1, vector<int>(n+1,0));
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         summatrix[i+1][j+1] = summatrix[i+1][j]+matrix[i][j];
        //     }
        // }
        // for(int j=1;j<n+1;j++){
        //     for(int i=1;i<m+1;i++){
        //         summatrix[i][j] += summatrix[i-1][j];
        //     }
        // }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                summatrix[i+1][j+1] = summatrix[i][j+1]+summatrix[i+1][j]-summatrix[i][j]+matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return summatrix[row2+1][col2+1] - summatrix[row1][col2+1] - summatrix[row2+1][col1] + summatrix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main(){
    vector<vector<int>> matrix = {
                                {3, 0, 1, 4, 2},
                                {5, 6, 3, 2, 1},
                                {1, 2, 0, 1, 5},
                                {4, 1, 0, 1, 7},
                                {1, 0, 3, 0, 5}
                                };
    int row1 = 1, col1 = 2, row2 = 2, col2 = 4;
    NumMatrix* obj = new NumMatrix(matrix);
    int param_1 = obj->sumRegion(row1,col1,row2,col2);
    cout<<param_1<<endl;
    return 0;
}