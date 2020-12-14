// 面试题 01.07. Rotate Matrix LCCI

// Given an image represented by an N x N matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

//  

// Example 1:

// Given matrix = 
// [
//   [1,2,3],
//   [4,5,6],
//   [7,8,9]
// ],

// Rotate the matrix in place. It becomes:
// [
//   [7,4,1],
//   [8,5,2],
//   [9,6,3]
// ]
// Example 2:

// Given matrix =
// [
//   [ 5, 1, 9,11],
//   [ 2, 4, 8,10],
//   [13, 3, 6, 7],
//   [15,14,12,16]
// ], 

// Rotate the matrix in place. It becomes:
// [
//   [15,13, 2, 5],
//   [14, 3, 4, 1],
//   [12, 6, 8, 9],
//   [16, 7,10,11]
// ]

#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>>& matrix){
    for (int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0;j<matrix[0].size();j++){
            if(j==matrix[0].size()-1){
                cout<<matrix[i][j];
            }else{
                cout<<matrix[i][j]<<',';
            }
        }
        cout<<endl;
    }
    cout<<"------------"<<endl;
}

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //上下翻转
        int m = matrix.size();
        int n = matrix[0].size();
        //对角线翻转  
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n-i-1;j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[m-j-1][n-i-1];
                matrix[m-j-1][n-i-1] = tmp;
            }
        }      
        print(matrix);
        for(int i = 0;i<m/2;i++){
            for(int j = 0;j<n;j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-i-1][j];
                matrix[n-i-1][j] = tmp;
            }
        } 
        print(matrix);
    }        
};

int main(){
    Solution s = Solution();
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    print(matrix);
    s.rotate(matrix);

    return 0;
}