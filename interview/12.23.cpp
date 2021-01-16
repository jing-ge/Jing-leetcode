// 面试题 17.23. Max Black Square LCCI
// Imagine you have a square matrix, where each cell (pixel) is either black or white Design an algorithm to find the maximum subsquare such that all four borders are filled with black pixels.

// Return an array [r, c, size], where r, c are the row number and the column number of the subsquare's upper left corner respectively, and size is the side length of the subsquare. If there are more than one answers, return the one that has smallest r. If there are more than one answers that have the same r, return the one that has smallest c. If there's no answer, return an empty array.

// Example 1:

// Input:
// [
//    [1,0,1],
//    [0,0,1],
//    [0,0,1]
// ]
// Output: [1,0,2]
// Explanation: 0 represents black, and 1 represents white, bold elements in the input is the answer.
// Example 2:

// Input:
// [
//    [0,1,1],
//    [1,0,1],
//    [1,1,0]
// ]
// Output: [0,0,1]
// Note:

// matrix.length == matrix[0].length <= 200

#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>>& matrix){
    for(auto t:matrix){
        for(int &i:t)cout<<i<<",";
        cout<<endl;
    }
}

class Solution {
public:
    vector<int> findSquare(vector<vector<int>>& matrix) {
        int res_r=0, res_c = 0, res = 0;
        int n = matrix.size();
        int cnt=0;
        //构建辅助矩阵
        vector<vector<int>> rmatrix = matrix,cmatrix = matrix;
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=0;j--){
                if(matrix[i][j]==0){
                    cnt++; 
                }else cnt = 0;
                rmatrix[i][j]=cnt;
            }
            cnt = 0;
        }
        cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=0;j--){
                if(matrix[j][i]==0){
                    cnt++;
                }else  cnt = 0;
                cmatrix[j][i]=cnt;
            }
            cnt = 0;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int maxsize = min(rmatrix[i][j],cmatrix[i][j]);
                if(maxsize==0)continue;
                for(int t=1;t<=maxsize;t++){
                    if(rmatrix[i+t-1][j]>=t&&cmatrix[i][j+t-1]>=t&&t>res){
                        res_r = i;res_c = j;res = t; 
                    }
                }
                
            }
        }
        if(res==0)return {};
        return {res_r,res_c,res};
    }
};

int main(){
    vector<vector<int>> matrix = {{1, 1, 1, 0, 1, 1, 0, 1, 0, 0},{0, 1, 0, 1, 1, 0, 0, 0, 1, 1},{0, 0, 1, 1, 0, 0, 1, 1, 1, 0},{0, 1, 1, 1, 0, 1, 0, 0, 1, 0},{1, 1, 0, 1, 1, 0, 1, 0, 0, 1}};
    Solution s = Solution();
    vector<int>res = s.findSquare(matrix);
    cout<<res[0]<<","<<res[1]<<","<<res[2]<<","<<endl;
    return 0;
}