// 85. Maximal Rectangle
// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

// Example 1:


// Input: matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}}
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.
// Example 2:

// Input: matrix = {}
// Output: 0
// Example 3:

// Input: matrix = {{'0'}}
// Output: 0
// Example 4:

// Input: matrix = {{'1'}}
// Output: 1
// Example 5:

// Input: matrix = {{'0','0'}}
// Output: 0
 

// Constraints:

// rows == matrix.length
// cols == matrix.length
// 0 <= row, cols <= 200
// matrix{i}{j} is '0' or '1'.
// 通过次数54,070提交次数108,373

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)return 0;
        int res = 0;
        vector<int>heights(matrix[0].size(),0);
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='0'){
                    heights[j] = 0;
                }else{
                    heights[j] = heights[j]+1;
                }
            }
            res = max(res,largestRectangleArea(heights));
        }
        return res;
    }
    int largestRectangleArea(vector<int> heights) {
        heights.push_back(0);
        heights.insert(heights.begin(),0);
        stack<int> s;
        int maxarea = 0;
        for(int i=0;i<heights.size();i++){
            while(!s.empty() && heights[i]<heights[s.top()]){
                int top = s.top();
                s.pop();
                maxarea = max(maxarea,heights[top]*(i-s.top()-1));
            }
            s.push(i);
        }
        return maxarea;
    }
};

int main(){
    Solution s = Solution();
    // vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    vector<vector<char>> matrix = {{'0','1'},{'1','0'}};
    int res = s.maximalRectangle(matrix);
    cout<<res<<endl;
    return 0;
}