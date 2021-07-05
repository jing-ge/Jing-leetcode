// 本题无跳出页面限制，支持使用本地IDE调试，最终以系统调试结果为准。
// 机器人漫步
// 详细描述
// 一个机器人要从起始点A和终点B。机器人从起点开始，每次能从上，下，左，右移动一步通过一个房间。并且每个房间只能路过一次。

// 设定机器人的健康数为H，如果经过的房间是正整数a，那么机器人经过这个房间就能获得对应的健康点数，健康数变成H+a，如果经过的房间为负数，那么机器人就会失去对应的健康点数a， 机器人的健康数变成H-a，问如果要保证机器人生命数一直是正数，H初始值至少为多少？

// 房间点数由一个二维数组M*N 表示，起点和终点由一个一维数组组成。

// 1 <= M,N <= 200

// m == rooms.length

// n == rooms[i].length

// -1000 <= rooms[i][j] <= 1000

// 0 <= i,j <= M,N

// 例子:


 

// 其他
// 时间限制: 1000ms

// 内存限制: 256.0MB

// 输入输出示例
// 示例1
// 输入
// 复制
// [[-2,-3,3],[-5,-10,1],[10,30,-5]],[0,0],[2,2]
// 输出
// 复制
// 7
// 示例2
// 输入
// 复制
// [[100]],[0,0],[0,0]
// 输出
// 复制
// 1

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    /**
     * Note: 类名、方法名、参数名已经指定，请勿修改
     *
     * 
     * 
     * @param rooms int整型vector<vector<>> 房间
     * @param startPoint int整型vector 起始点
     * @param endPoint int整型vector 终点
     * @return int整型
     */
    int minimumInitHealth(vector<vector<int> >& rooms, vector<int>& startPoint, vector<int>& endPoint) {

    }
    int dfs(vector<vector<int> >& rooms, vector<int>& startPoint, vector<int>& endPoint, int cur, int minHealth){
        
    }
};


int main(){
    Solution s;
    vector<vector<int>> rooms = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
    // vector<vector<int>> rooms = {{100}};
    vector<int> startPoint = {0,0};
    vector<int> endPoint = {2,2};
    int res = s.minimumInitHealth(rooms,startPoint,endPoint);
    cout<<res<<endl;
}