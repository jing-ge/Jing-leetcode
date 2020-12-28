// 面试题 16.13. Bisect Squares LCCI
// Given two squares on a two-dimensional plane, find a line that would cut these two squares in half. Assume that the top and the bottom sides of the square run parallel to the x-axis.

// Each square consists of three values, the coordinate of bottom left corner [X,Y] = [square[0],square[1]], and the side length of the square square[2]. The line will intersect to the two squares in four points. Return the coordinates of two intersection points [X1,Y1] and [X2,Y2] that the forming segment covers the other two intersection points in format of {X1,Y1,X2,Y2}. If X1 != X2, there should be X1 < X2, otherwise there should be Y1 <= Y2.

// If there are more than one line that can cut these two squares in half, return the one that has biggest slope (slope of a line parallel to the y-axis is considered as infinity).

// Example:

// Input: 
// square1 = {-1, -1, 2}
// square2 = {0, -1, 2}
// Output: {-1,0,2,0}
// Explanation: y = 0 is the line that can cut these two squares in half.
// Note:

// square.length == 3
// square[2] > 0

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<double> cutSquares(vector<int>& square1, vector<int>& square2) {

    }
};

int main(){
    Solution s =Solution();
    vector<int> square1 = {-1, -1, 2},square2 = {0, -1, 2};
    vector<int> res =s.cutSquares(square1,square2);
    return 0;
}