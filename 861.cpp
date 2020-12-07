// 861. Score After Flipping Matrix
// We have a two dimensional matrix A where each value is 0 or 1.

// A move consists of choosing any row or column, and toggling each value in that row or column: changing all 0s to 1s, and all 1s to 0s.

// After making any number of moves, every row of this matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

// Return the highest possible score.

//  

// Example 1:

// Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
// Output: 39
// Explanation:
// Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
// 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
//  

// Note:

// 1 <= A.length <= 20
// 1 <= A[0].length <= 20
// A[i][j] is 0 or 1.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        //step 1
        for(int i = 0;i<m;i++){
            if(A[i][0]==0){
                for(int j=0;j<n;j++){
                    A[i][j] = A[i][j]?0:1;
                }
            }
        }
        //step 2 统计数量
        vector<int> r(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(A[i][j]==1){
                    r[j]++;
                }
            }
        }
        //step3 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((2*r[j])<m){
                    A[i][j] = (A[i][j]==1)?0:1;
                }
            }
        }
        
        int res = 0;
        for(int i=0;i<m;i++){
            int tmp = 0;
            for(int j=0;j<n;j++){
                tmp+= A[i][j]*pow(2,n-j-1);
            }
            // cout<<tmp<<endl;
            res+= tmp;
        }
        return res;
    }

    int matrixScore2(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        int res = m*(1<<(n-1));
        for(int j=1;j<n;j++){
            int n_1 = 0;
            for(int i=0;i<m;i++){
                if(A[i][0]==1){
                    n_1 += A[i][j];
                }else{
                    n_1 += (1-A[i][j]);
                }
            }
            res += ((2*n_1)>m?n_1:m-n_1)*(1<<(n-j-1));
        }
        return res;
    }

    void print(vector<vector<int>>data){
        for(auto d:data){
            for(int i:d){
                cout<<i<<",";
            }
            cout<<endl;
        }
    }
    void print(vector<int>d){
        for(auto i:d){
            cout<<i<<",";
        }
        cout<<endl;
    }
};

int main(){
    vector<vector<int>> A = {{0,1},{0,1},{1,0},{0,0}};
    
    Solution s = Solution();
    int res = s.matrixScore2(A);
    cout<<res<<endl;
    return 0;
}