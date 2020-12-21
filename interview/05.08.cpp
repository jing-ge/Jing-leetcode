// 面试题 05.08. Draw Line LCCIA monochrome screen is stored as a single array of int, allowing 32 consecutive pixels to be stored in one int. The screen has width w, where w is divisible by 32 (that is, no byte will be split across rows). The height of the screen, of course, can be derived from the length of the array and the width. Implement a function that draws a horizontal line from (x1, y) to (x2, y).

// Given the length of the array, the width of the array (in bit), start position x1 (in bit) of the line, end position x2 (in bit) of the line and the row number y of the line, return the array after drawing.

// Example1:

//  Input: length = 1, w = 32, x1 = 30, x2 = 31, y = 0
//  Output: [3]
//  Explanation: After drawing a line from (30, 0) to (31, 0), the screen becomes [0b000000000000000000000000000000011].
// Example2:

//  Input: length = 3, w = 96, x1 = 0, x2 = 95, y = 0
//  Output: [-1, -1, -1]

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

void print(vector<int>&nums){
    for(int i:nums){
        cout<<i<<",";
    }
    cout<<endl;
}

class Solution {
public:
    vector<int> drawLine(int length, int w, int x1, int x2, int y) {
        vector<int> p(length,0);
        if(length==0)return p;
        int row = w/32;
        int start = row*y+x1/32;
        int start_s = x1%32;
        int end = row*y+x2/32;
        int end_s = 31-x2%32;
        for(int i=start;i<=end;i++){
            p[i] = -1;
        }
        if(start==end){
            p[start] = (unsigned int)p[start]>>start_s+end_s;
            p[end] = (unsigned int)p[end]<<end_s;
        }else{
            p[start] = (unsigned int)p[start]>>start_s;
            p[end] = (unsigned int)p[end]<<end_s;
        }
        return p;
    }
};

int main(){
    Solution s =Solution();
    int length = 1, w = 32, x1 = 30, x2 = 31, y = 0;
    vector<int> res = s.drawLine(length,w,x1,x2,y);
    print(res);
    return 0;
}