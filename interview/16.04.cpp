// 面试题 16.04. Tic-Tac-Toe LCCI
// Design an algorithm to figure out if someone has won a game of tic-tac-toe. Input is a string array of size N x N, including characters " ", "X" and "O", where " " represents a empty grid.

// The rules of tic-tac-toe are as follows:

// Players place characters into an empty grid(" ") in turn.
// The first player always place character "O", and the second one place "X".
// Players are only allowed to place characters in empty grid. Replacing a character is not allowed.
// If there is any row, column or diagonal filled with N same characters, the game ends. The player who place the last charater wins.
// When there is no empty grid, the game ends.
// If the game ends, players cannot place any character further.
// If there is any winner, return the character that the winner used. If there's a draw, return "Draw". If the game doesn't end and there is no winner, return "Pending".

// Example 1:

// Input:  board = ["O X"," XO","X O"]
// Output:  "X"
// Example 2:

// Input:  board = ["OOX","XXO","OXO"]
// Output:  "Draw"
// Explanation:  no player wins and no empty grid left
// Example 3:

// Input:  board = ["OOX","XXO","OX "]
// Output:  "Pending"
// Explanation:  no player wins but there is still a empty grid
// Note:

// 1 <= board.length == board[i].length <= 100
// Input follows the rules.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string tictactoe(vector<string>& board) {
        int b = 0,n = board.size();
        int sum_row = 0,sum_col = 0,l_diag = 0,r_diag = 0,isfull = 1;
        for(int i=0;i<n;i++){
            sum_row = 0;sum_col = 0;
            l_diag += board[i][i];
            r_diag += board[i][n-i-1];
            for(int j = 0;j <n;j++){
                sum_row += board[i][j];
                sum_col += board[j][i];
                if(board[i][j]==' ')isfull = 0;
            }
            if(sum_row==((int)'X')*n||sum_col==((int)'X')*n)return "X";
            if(sum_row==((int)'O')*n||sum_col==((int)'O')*n)return "O";
        }
        if(l_diag==((int)'X')*n||r_diag==((int)'X')*n)return "X";
        if(l_diag==((int)'O')*n||r_diag==((int)'O')*n)return "O";
        if(isfull){
            return "Draw";
        }else{
            return "Pending";
        }
    }
};

int main(){
    vector<string> board = {"O X"," XO","X O"};
    Solution s = Solution();
    string res = s.tictactoe(board);
    cout<<res<<endl;
    return 0;
}