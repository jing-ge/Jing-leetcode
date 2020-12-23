// 面试题 08.10. Color Fill LCCIImplement the "paint fill" function that one might see on many image editing programs. That is, given a screen (represented by a two-dimensional array of colors), a point, and a new color, fill in the surrounding area until the color changes from the original color.

// Example1:

// Input: 
// image = [[1,1,1],[1,1,0],[1,0,1]] 
// sr = 1, sc = 1, newColor = 2
// Output: [[2,2,2],[2,2,0],[2,0,1]]
// Explanation: 
// From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
// by a path of the same color as the starting pixel are colored with the new color.
// Note the bottom corner is not colored 2, because it is not 4-directionally connected
// to the starting pixel.
// Note:

// The length of image and image[0] will be in the range [1, 50].
// The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
// The value of each color in image[i][j] and newColor will be an integer in [0, 65535].


#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>>&image){
    for(auto i:image){
        for(int j:i){
            cout<<j<<",";
        }
        cout<<endl;
    }
}

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]!=newColor){
            dfs(image,sr,sc,newColor,image[sr][sc]);
        }
        return image;
    }

    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor,int oldColor){
        // cout<<sr<<","<<sc<<endl;
        int m = image.size();
        int n = image[0].size();
        if(sr>=0&&sr<m&&sc>=0&&sc<n&&image[sr][sc]==oldColor){
            if(image[sr][sc]==newColor)return;
            image[sr][sc]=newColor;
            dfs(image,sr-1,sc,newColor,oldColor);
            dfs(image,sr+1,sc,newColor,oldColor);
            dfs(image,sr,sc-1,newColor,oldColor);
            dfs(image,sr,sc+1,newColor,oldColor);
        }
    }
};

int main(){
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    // vector<vector<int>> image = {{0,0,0},{0,1,1}};
    Solution s = Solution();
    s.floodFill(image,1,1,2);
    print(image);
    return 0;
}
