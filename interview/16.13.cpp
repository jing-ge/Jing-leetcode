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
#include <algorithm>

using namespace std;

void print(vector<vector<double>>&r){
    for(auto res:r){
        for(double i:res){
            cout<<i<<",";
        }
        cout<<endl;
    }
}

class Solution {
public:
    vector<double> cutSquares(vector<int>& square1, vector<int>& square2) {
        double cx1 = square1[0] + square1[2]/2.0;
        double cy1 = square1[1] + square1[2]/2.0;
        double cx2 = square2[0] + square2[2]/2.0;
        double cy2 = square2[1] + square2[2]/2.0;
        vector<vector<double>>res;
        cout<<cx1<<","<<cy1<<";"<<cx2<<","<<cy2<<endl;
        cout<<"-----------"<<endl;
        if(cx1==cx2){
            res.push_back({cx1,(double)square1[1]});
            res.push_back({cx1,(double)square1[1]+square1[2]});
            res.push_back({cx2,(double)square2[1]});
            res.push_back({cx1,(double)square2[1]+square2[2]});
        } else if(cy1 == cy2){
            res.push_back({(double)square1[0],cy1});
            res.push_back({(double)square1[0]+square1[2],cy1});
            res.push_back({(double)square2[0],cy2});
            res.push_back({(double)square2[0]+square2[2],cy2});
        }else
        {
            double x1 = square1[0] ;
            double x2 = square1[0]+square1[2];
            double x3 = square2[0];
            double x4 = square2[0]+square2[2];

            double y1 = (x1-cx1)/(cx2-cx1)*(cy2-cy1)+cy1;
            double y2 = (x2-cx1)/(cx2-cx1)*(cy2-cy1)+cy1;;
            double y3 = (x3-cx1)/(cx2-cx1)*(cy2-cy1)+cy1;;
            double y4 = (x4-cx1)/(cx2-cx1)*(cy2-cy1)+cy1;;

            double yy1 = square1[1] ;
            double yy2 = square1[1]+square1[2];
            double yy3 = square2[1];
            double yy4 = square2[1]+square2[2];

            double xx1 = (yy1-cy1)/(cy2-cy1)*(cx2-cx1)+cx1;
            double xx2 = (yy2-cy1)/(cy2-cy1)*(cx2-cx1)+cx1;
            double xx3 = (yy3-cy1)/(cy2-cy1)*(cx2-cx1)+cx1;
            double xx4 = (yy4-cy1)/(cy2-cy1)*(cx2-cx1)+cx1;
            if(x1>=square1[0]&&x1<=square1[0]+square1[2]&&y1>=square1[1]&&y1<=square1[1]+square1[2])res.push_back({x1,y1});
            if(x2>=square1[0]&&x2<=square1[0]+square1[2]&&y2>=square1[1]&&y2<=square1[1]+square1[2])res.push_back({x2,y2});
            if(x3>=square2[0]&&x3<=square2[0]+square2[2]&&y3>=square2[1]&&y3<=square2[1]+square2[2])res.push_back({x3,y3});
            if(x4>=square2[0]&&x4<=square2[0]+square2[2]&&y4>=square2[1]&&y4<=square2[1]+square2[2])res.push_back({x4,y4});

            if(xx1>=square1[0]&&xx1<=square1[0]+square1[2]&&yy1>=square1[1]&&yy1<=square1[1]+square1[2])res.push_back({xx1,yy1});
            if(xx2>=square1[0]&&xx2<=square1[0]+square1[2]&&yy2>=square1[1]&&yy2<=square1[1]+square1[2])res.push_back({xx2,yy2});
            if(xx3>=square2[0]&&xx3<=square2[0]+square2[2]&&yy3>=square2[1]&&yy3<=square2[1]+square2[2])res.push_back({xx3,yy3});
            if(xx4>=square2[0]&&xx4<=square2[0]+square2[2]&&yy4>=square2[1]&&yy4<=square2[1]+square2[2])res.push_back({xx4,yy4});
        }
        sort(res.begin(),res.end());
        return {res[0][0],res[0][1],res.back()[0],res.back()[1]};
    }
};

int main(){
    Solution s =Solution();
    vector<int> square1 = {68,130,64},square2 = {-230,194,7};
    vector<double> res =s.cutSquares(square1,square2);
    for(double i:res){
        cout<<i<<",";
    }
    cout<<endl;
    return 0;
}