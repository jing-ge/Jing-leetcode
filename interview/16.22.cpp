// 面试题 16.22. Langtons Ant LCCI
// An ant is sitting on an infinite grid of white and black squares. It initially faces right. All squares are white initially.

// At each step, it does the following:

// (1) At a white square, flip the color of the square, turn 90 degrees right (clockwise), and move forward one unit.

// (2) At a black square, flip the color of the square, turn 90 degrees left (counter-clockwise), and move forward one unit.

// Write a program to simulate the first K moves that the ant makes and print the final board as a grid.

// The grid should be represented as an array of strings, where each element represents one row in the grid. The black square is represented as 'X', and the white square is represented as '_', the square which is occupied by the ant is represented as 'L', 'U', 'R', 'D', which means the left, up, right and down orientations respectively. You only need to return the minimum matrix that is able to contain all squares that are passed through by the ant.

// Example 1:

// Input: 0
// Output: ["R"]
// Example 2:

// Input: 2
// Output:
// [
//   "_X",
//   "LX"
// ]
// Example 3:

// Input: 5
// Output:
// [
//   "_U",
//   "X_",
//   "XX"
// ]
// Note:

// K <= 100000
// 通过次数1,582提交次数2,741

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Ant{
public:
    int x=0;
    int y = 0;
    string dir = "LURD";
    int dirt = 2;
    int left= 0,right = 0,top = 0,bottom=0;
    vector<vector<int>> d = {{-1,0},{0,1},{1,0},{0,-1}};
    void step(char block){
        if(block=='_'){
            dirt = (dirt+1)%4;
        }else{
            dirt = (dirt-1+4)%4;
        }
        x+= d[dirt][0];
        y+= d[dirt][1];
        if(left>x)left = x;
        if(right<x)right =x;
        if(top<y)top = y;
        if(bottom>y)bottom = y;
    }
    char direction(){
        return dir[dirt];
    }
    vector<int> position(){
        return {x,y};
    }
};


class Solution {
public:
    vector<string> printKMoves(int K) {
        set<vector<int>> s;
        Ant ant = Ant();
        for(int i=0;i<K;i++){
            if(s.count(ant.position())){
                s.erase(ant.position());
                ant.step('X');
            }else{
                s.insert(ant.position());
                ant.step('_');
            }
            cout<<ant.x<<","<<ant.y<<","<<ant.direction()<<endl;
        }
        cout<<"---------"<<endl;
        // vector<string> res;
        //convert to string
        // for(int i=ant.top;i>=ant.bottom;i--){
        //     string tmp = "";
        //     for(int j = ant.left;j<=ant.right;j++){
        //         if(i==ant.y&&j==ant.x){
        //             tmp+=string(1,ant.direction());
        //             continue;
        //         }
        //         if(s.count({j,i}))tmp = tmp + string("X");
        //         else tmp = tmp +string("_");
        //     }
        //     res.push_back(tmp);
        // }
        vector<string> res(ant.top-ant.bottom+1,string(ant.right-ant.left+1,'_'));
        for(auto it = s.begin();it!=s.end();it++){
            int i = ant.top-(*it)[1],j = (*it)[0]-ant.left;
            res[i][j] = 'X';
        }
        res[ant.top-ant.y][ant.x-ant.left] = ant.direction();
        return res;
    }
};

int main(){
    Solution s = Solution();
    vector<string>res = s.printKMoves(5);
    for(string str:res){
        cout<<str<<endl;
    }
    return 0;
}