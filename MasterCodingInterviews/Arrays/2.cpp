// You are given an array of positive integers where 
// each integer represents the height of a vertical 
// line on a chat. Find two lines which together with 
// the x-axis forms a container thar would hold the 
// greatest amout of water Return the area of water 
// it would hold.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea2(vector<int>& height) {
        int res = 0;
        for(int i=0;i<height.size();i++){
            for (int j = i+1; j < height.size(); j++)
            {
                int t = min(height[i],height[j])*(j-i);
                res = max(res,t);
            }
        }
        return res;
    }
    int maxArea(vector<int>& height){
        int left = 0,right = height.size()-1,res = 0;
        while(left<right){
            int hei = min(height[left],height[right]);
            res = max(hei*(right-left),res);
            if(height[left]<=height[right])left++;
            else right--;
        }
        return res;
    }
};


int main(){
    Solution s;
    vector<int> heights = {1,8,6,2,5,4,8,3,7};
    int res = s.maxArea(heights);
    cout<<res<<endl;
    return 0;
}