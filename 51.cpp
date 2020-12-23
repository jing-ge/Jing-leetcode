// 面试题 08.12. Eight Queens LCCIWrite an algorithm to print all ways of arranging n queens on an n x n chess board so that none of them share the same row, column, or diagonal. In this case, "diagonal" means all diagonals, not just the two that bisect the board.

// Notes: This problem is a generalization of the original one in the book.

// Example:

//  Input: 4
//  Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
//  Explanation: 4 queens has following two solutions
// [
//  [".Q..",  // solution 1
//   "...Q",
//   "Q...",
//   "..Q."],

//  ["..Q.",  // solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]


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
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        backtrack(board,0);
        return res;
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
    vector<vector<string>> res = s.solveNQueens(4);
    print(res);
    return 0;
}