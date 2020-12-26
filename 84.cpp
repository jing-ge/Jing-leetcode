// 84. Largest Rectangle in Histogram
// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

 


// Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

 


// The largest rectangle is shown in the shaded area, which has area = 10 unit.

 

// Example:

// Input: [2,1,5,6,2,3]
// Output: 10
// 通过次数107,870提交次数256,012

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
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
    vector<int> heights = {2,1,5,6,2,3};
    Solution s = Solution();
    int res = s.largestRectangleArea(heights);
    cout<<res<<endl;
    return 0;
}