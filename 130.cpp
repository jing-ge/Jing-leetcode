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

class UnionFind{
public:
    int n;
    vector<int> parent;
    vector<int> size;
    UnionFind(int _n){
        n = _n;
        for(int i=-0;i<n;i++){
            parent.push_back(i);
            size.push_back(1);
        }
    }
    int root(int i){
        while(parent[i]!=i){
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;
    }
    bool merge(int i, int j){
        i = root(i);
        j = root(j);
        if(i==j)return false;
        if(size[i]<size[j]){
            parent[i] = j;
            size[j]+=size[i];
        }else{
            parent[j] = i;
            size[i] += size[j];
        }
        n--;
        return true;
    }
};

class Solution {
public:
    vector<vector<bool>>visited;
    void solve_dfs(vector<vector<char>>& board) {
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
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m==0)return;
        int n = board[0].size();
        int dummy = m*n;
        UnionFind uf(m*n+1);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    int idx = i*n+j;
                    if(i==0||i==m-1||j==0||j==n-1){
                        uf.merge(idx,dummy);
                    }
                    if(i+1<m&&board[i+1][j]=='O')uf.merge((i+1)*n+j,idx);
                    if(j+1<n&&board[i][j+1]=='O')uf.merge(i*n+j+1,idx);
                    if(i-1>=0&&board[i-1][j]=='O')uf.merge((i-1)*n+j,idx);
                    if(j-1>=0&&board[i][j-1]=='O')uf.merge(i*n+j-1,idx);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'&&(uf.root(i*n+j)!=uf.root(dummy))){
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main(){
    Solution s;
    // vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    //  vector<vector<char>> board = {{'X','O','X'},{'O','X','O'},{'X','O','X'}};
    vector<vector<char>> board = {{'X','O','X','O','X','O'},{'O','X','O','X','O','X'},{'X','O','X','O','X','O'},{'O','X','O','X','O','X'}};
    for(auto t:board){
        for(auto c:t){
            cout<<c;
        }
        cout<<endl;
    }
    cout<<"------------------"<<endl;
    s.solve(board);
    for(auto t:board){
        for(auto c:t){
            cout<<c;
        }
        cout<<endl;
    }
    return 0;
}