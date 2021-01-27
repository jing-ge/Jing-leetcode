// 130. Surrounded Regions
// Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded region.

// Example:

// X X X X
// X O O X
// X X O X
// X O X X
// After running your function, the board should be:

// X X X X
// X X X X
// X X X X
// X O X X
// Explanation:

// Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

// 通过次数85,939提交次数203,333
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<bool>>visited;
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m==0)return;
        int n = board[0].size();
        visited = vector<vector<bool>>(m,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            if(board[0][i]=='O')dfs(0,i,board);
            if(board[m-1][i]=='O')dfs(m-1,i,board);
        }
        for(int i=1;i<m-1;i++){
            if(board[i][0]=='O')dfs(i,0,board);
            if(board[i][n-1]=='O')dfs(i,n-1,board);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='#')board[i][j]='O';
                else if(board[i][j]=='O')board[i][j]='X';
            }
        }
    }

    void dfs(int i,int j,vector<vector<char>>& board){
        if(i<0||i>=board.size()||j<0||j>=board[0].size()||visited[i][j]||board[i][j]=='X')return;
        if(board[i][j]=='O')board[i][j]='#';
        visited[i][j] = true;
        dfs(i+1,j,board);
        dfs(i-1,j,board);
        dfs(i,j+1,board);
        dfs(i,j-1,board);
    }
};

int main(){
    Solution s;
    // vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
     vector<vector<char>> board = {{'X','O','X'},{'O','X','O'},{'X','O','X'}};
    s.solve(board);
    for(auto t:board){
        for(auto c:t){
            cout<<c;
        }
        cout<<endl;
    }
    return 0;
}