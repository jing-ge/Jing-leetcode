// 面试题 01.08. Zero Matrix LCCI
// Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0.

//  

// Example 1:

// Input: 
// [
//   [1,1,1],
//   [1,0,1],
//   [1,1,1]
// ]
// Output: 
// [
//   [1,0,1],
//   [0,0,0],
//   [1,0,1]
// ]
// Example 2:

// Input: 
// [
//   [0,1,2,0],
//   [3,4,5,2],
//   [1,3,1,5]
// ]
// Output: 
// [
//   [0,0,0,0],
//   [0,4,5,0],
//   [0,3,1,0]
// ]

#include <iostream>
#include <unordered_set>
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
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows,cols;
        for(int i=0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    if(rows.find(i)==rows.end()){
                        rows.insert(i);
                    }
                    if(cols.find(j)==cols.end()){
                        cols.insert(j);
                    }
                }
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(rows.find(i)!=rows.end()||cols.find(j)!=cols.end()){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main(){
    Solution s = Solution();
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    print(matrix);
    s.setZeroes(matrix);
    print(matrix);
    return 0;
}