// 62. Unique Paths
// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

// How many possible unique paths are there?

//  
// xample 1:


// Input: m = 3, n = 7
// Output: 28
// Example 2:

// Input: m = 3, n = 2
// Output: 3
// Explanation:
// From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Down -> Down
// 2. Down -> Down -> Right
// 3. Down -> Right -> Down
// Example 3:

// Input: m = 7, n = 3
// Output: 28
// Example 4:

// Input: m = 3, n = 3
// Output: 6

#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>>d){
    for(auto i:d){
        for(auto j:i){
            cout<<j<<",";
        }
        cout<<endl;
    }
}

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> table (m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            table[i][0] = 1;
        }
        for(int j = 0;j<n;j++){
            table[0][j] = 1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                table[i][j] = table[i-1][j]+ table[i][j-1];
            }
        }
        // print(table);
        return table[m-1][n-1];
    }
};

int main(){
    int m=7;
    int n = 3;
    Solution s = Solution();
    int res = s.uniquePaths(m,n);
    cout<<res<<endl;
    return 0;
}