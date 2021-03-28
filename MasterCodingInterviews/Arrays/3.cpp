// Given an array of integers representing an elevation map
// where the width of each bar is 1, return how much rain water
// can be trapped

// examples
// [0,1,0,2,1,0,3,1,0,1,2]

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();
        if(n==0)return res;
        vector<int> left(n),right(n);
        left[0] = height[0];
        right[n-1] = height[n-1];
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            right[i] = max(right[i+1],height[i]);
        }
        for(int i=0;i<n;i++){
            int t = min(left[i],right[i]);
            if(t>height[i])res+=(t-height[i]);
        }
        return res;
    }
    int trap2(vector<int> &heights){
        int n = heights.size();
        if(n==0) return 0;
        int left = 0,right = n-1;
        int lmax = heights[0],rmax = heights[n-1];
        int res = 0;
        while(left<=right){
            lmax = max(lmax,heights[left]);
            rmax = max(rmax,heights[right]);
            if(lmax<rmax){
                res+= lmax-heights[left];
                left++;
            }else{
                res+= rmax-heights[right];
                right--;
            }
        }
        return res;
    }
};

int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    int res = s.trap2(height);
    cout<<res<<endl;
    return 0;
}