// 59. Spiral Matrix II
// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

 

// Example 1:


// Input: n = 3
// Output: [[1,2,3],[8,9,4],[7,6,5]]
// Example 2:

// Input: n = 1
// Output: [[1]]
 

// Constraints:

// 1 <= n <= 20
// 通过次数73,194提交次数92,069

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int*> res;
        vector<vector<int>> matrix;
        if(n==0)return matrix;
        matrix = vector<vector<int>>(n,vector<int>(n,0));
        int u = 0;
        int d = matrix.size()-1;
        int l = 0;
        int r = matrix[0].size()-1;
        while(true){
            for(int i=l;i<=r;i++){
                res.push_back(&matrix[u][i]);
            }
            u++;
            if(u>d)break;
            for(int i=u;i<=d;i++){
                res.push_back(&matrix[i][r]);
            }
            r--;
            if(r<l)break;
            for(int i=r;i>=l;i--){
                res.push_back(&matrix[d][i]);
            }
            d--;
            if(d<u)break;
            for(int i=d;i>=u;i--){
                res.push_back(&matrix[i][l]);
            }
            l++;
            if(l>r)break;
        }
        for(int i=0;i<n*n;i++){
            *res[i] = i+1;
        }
        return matrix;
    }
};

int main(){
    int n = 3;
    Solution s;
    vector<vector<int>> res = s.generateMatrix(n);
    for(auto t:res){
        for(int i:t){
            cout<<i<<",";
        }
        cout<<endl;
    }
    return 0;
}