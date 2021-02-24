// 832. Flipping an Image
// Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.

// To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].

// To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].

// Example 1:

// Input: [[1,1,0],[1,0,1],[0,0,0]]
// Output: [[1,0,0],[0,1,0],[1,1,1]]
// Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
// Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
// Example 2:

// Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
// Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
// Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
// Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
// Notes:

// 1 <= A.length = A[0].length <= 20
// 0 <= A[i][j] <= 1
// 通过次数61,245提交次数77,702

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> res = A;
        int m = res.size(),n = res[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n/2;j++){
                if(res[i][j]==res[i][n-j-1]){
                    res[i][j] ^= 1;
                    res[i][n-j-1] ^= 1;
                }
            }
            if(n%2)res[i][n/2] ^= 1;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> A = {{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}};
    vector<vector<int>> res = s.flipAndInvertImage(A);
    for(auto t:res){
        for(int i:t){
            cout<<i<<",";
        }
        cout<<endl;
    }
    return 0;
}