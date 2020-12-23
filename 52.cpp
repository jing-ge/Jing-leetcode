// 52. N-Queens IIThe n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return the number of distinct solutions to the n-queens puzzle.

//  

// Example 1:


// Input: n = 4
// Output: 2
// Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
// Example 2:

// Input: n = 1
// Output: 1


#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(vector<vector<string>> res){
    for(auto i:res){
        for(string s:i){
            cout<<s<<endl;
        }
        cout<<"-------------"<<endl;
    }
}
class Solution {
public:
    vector<vector<string>>res;
    int totalNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        backtrack(board,0);
        return res.size();
    }
    void backtrack(vector<string>&board,int row){
        if(row==board.size()){
            res.push_back(board);
            return;
        }
        int n = board[row].size();
        for(int col = 0;col<n;col++){
            if(!isValid(board,row,col))continue;
            board[row][col] = 'Q';
            backtrack(board,row+1);
            board[row][col] = '.';
        }
    }
    bool isValid(vector<string>&board,int row, int col){
        int n = board.size();
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q')return false;
        }
        for(int i = row-1,j = col-1;i>=0&&j>=0;i--,j--){
            if(board[i][j]=='Q')return false;
        }
        for(int i = row-1,j = col+1;i>=0&&j<n;i--,j++){
            if(board[i][j]=='Q')return false;
        }
        return true;
    }
};

int main(){
    Solution s = Solution();
    int res = s.solveNQueens(4);
    cout<<res<<endl;
    return 0;
}