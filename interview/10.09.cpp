// 面试题 10.09. Sorted Matrix Search LCCI
// Given an M x N matrix in which each row and each column is sorted in ascending order, write a method to find an element.

// Example:

// Given matrix:

// {
//   {1,   4,  7, 11, 15},
//   {2,   5,  8, 12, 19},
//   {3,   6,  9, 16, 22},
//   {10, 13, 14, 17, 24},
//   {18, 21, 23, 26, 30}
// }
// Given target = 5, return true.

// Given target = 20, return false.

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x = matrix.size()-1;
        int y = 0;
        while(x>=0&&x<matrix.size()&&y>=0&&y<matrix[0].size()){
            if(matrix[x][y]==target)return true;
            else if(matrix[x][y]>target)x--;
            else y++;
        }
        return false;
    }
};

int main(){
    vector<vector<int>> matrix = {
                                    {1,   4,  7, 11, 15},
                                    {2,   5,  8, 12, 19},
                                    {3,   6,  9, 16, 22},
                                    {10, 13, 14, 17, 24},
                                    {18, 21, 23, 26, 30}
                                };
    int target = 5;
    Solution s = Solution();
    bool res = s.searchMatrix(matrix,target);
    cout<<res<<endl;
    return 0;
}