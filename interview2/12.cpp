// 剑指 Offer 12. 矩阵中的路径
// 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

 

// 例如，在下面的 3×4 的矩阵中包含单词 "ABCCED"（单词中的字母已标出）。



 

// 示例 1：

// 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// 输出：true
// 示例 2：

// 输入：board = [["a","b"],["c","d"]], word = "abcd"
// 输出：false
 

// 提示：

// 1 <= board.length <= 200
// 1 <= board[i].length <= 200
// board 和 word 仅由大小写英文字母组成
 

// 注意：本题与主站 79 题相同：https://leetcode-cn.com/problems/word-search/

#include<iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int m,n;
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(board,word,i,j,0))return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board,string word,int i,int j,int idx){
        if(word.size()==idx)return true;
        if(i>=m||j>=n||i<0||j<0||word[idx]!=board[i][j])return false;
        board[i][j] = '\0';
        bool res = dfs(board,word,i+1,j,idx+1)||dfs(board,word,i-1,j,idx+1)||dfs(board,word,i,j+1,idx+1)||dfs(board,word,i,j-1,idx+1);
        board[i][j] = word[idx];
        return res;
    }
};

int main(){
    Solution s;
    // vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    vector<vector<char>> board = {{'a'}};
    string word = "ab";
    bool res = s.exist(board,word);
    cout<<res<<endl;
    return 0;
}