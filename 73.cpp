// 73. Set Matrix Zeroes
// Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.

// Follow up:

// A straight forward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?
 

// Example 1:


// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]
// Example 2:


// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

// Constraints:

// m == matrix.length
// n == matrix[0].length
// 1 <= m, n <= 200
// -231 <= matrix[i][j] <= 231 - 1
// 通过次数74,160提交次数131,414

#include <vector>
#include <iostream>
#include <set>

using namespace std;

void print(vector<vector<int>> &matrix){
    for(auto &t:matrix){
        for(int &i:t){
            cout<<i<<",";
        }
        cout<<endl;
    }
}

class Solution {
public:
    //使用集合标记
    void setZeroes1(vector<vector<int>>& matrix) {
        set<int> row,col;
        int m = matrix.size(),n = matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(auto t = row.begin();t != row.end();t++){
            for(int j=0;j<n;j++){
                matrix[*t][j]=0;
            }
        }
        for(auto t = col.begin();t != col.end();t++){
            for(int j=0;j<m;j++){
                matrix[j][*t]=0;
            }
        }
    }
    //使用数组标记
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(),n = matrix[0].size();
        vector<int> row(m),col(n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row[i]||col[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    print(matrix);
    s.setZeroes(matrix);
    print(matrix);
    return 0;
}