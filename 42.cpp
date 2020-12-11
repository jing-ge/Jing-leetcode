// 42. Trapping Rain Water
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

//  

// Example 1:


// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9


#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>d){
    for(int i:d){
        cout<<i<<',';
    }
    cout<<endl;
}

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==0)return 0;
        int ans = 0;
        for(int i = 0;i<n;i++){
            int lmax = 0,rmax = 0;
            for(int j = i;j<n;j++)
                rmax = rmax>height[j]?rmax:height[j];
            for(int j = i;j>=0;j--)
                lmax = lmax>height[j]?lmax:height[j];
            ans += min(lmax,rmax)-height[i];
        }
        return ans;
    }
    int trap2(vector<int>& height) {
        if(height.empty())return 0;
        int n = height.size();
        vector<int> lmax(n),rmax(n);
        lmax[0] = height[0];
        rmax[n-1] = height[n-1];
        for(int i=1;i<n;i++)
            lmax[i] = lmax[i-1]>height[i]?lmax[i-1]:height[i];
        for(int i=n-2;i>=0;i--)
            rmax[i] = rmax[i+1]>height[i]?rmax[i+1]:height[i];
        int ans = 0;
        for(int i = 0;i<n;i++){
            // cout<<lmax[i]<<","<<rmax[i]<<endl;
            ans += min(lmax[i],rmax[i])-height[i];
        }
        return ans;
    }
    int trap3(vector<int>& height) {
        if(height.empty())return 0;
        int n = height.size();
        int left = 0,right = n-1;
        int l_max = height[0];
        int r_max = height[n-1];
        int ans = 0;
        while(left<=right){
            l_max = max(l_max,height[left]);
            r_max = max(r_max,height[right]);
            if(l_max<r_max){
                ans += l_max-height[left];
                left++;
            }else{
                ans += r_max-height[right];
                right--;
            }
        }
        return ans;
    }
};

int main (){
    Solution s = Solution();
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int res = s.trap3(height);
    cout<<res<<endl;
    return 0;
}