// 面试题 17.21. Volume of Histogram LCCI
// Imagine a histogram (bar graph). Design an algorithm to compute the volume of water it could hold if someone poured water across the top. You can assume that each histogram bar has width 1.



// The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of water (blue section) are being trapped. Thanks Marcos for contributing this image!

// Example:

// Input: [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// 通过次数6,809提交次数11,022

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void print(vector<int> & t){
    for(int &i:t)cout<<i<<",";
    cout<<endl;
}

class Solution {
public:
    int trap1(vector<int>& height) {
        int n = height.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        left[0] = height[0];
        right[n-1] = height[n-1];
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1],height[i]);
            right[n-i-1] = max(right[n-i],height[n-i]);
        }
        int res = 0;
        for(int i=0;i<n;i++)
        {
            int t = min(left[i],right[i])-height[i];
            res += t>0?t:0;
        }
        return res;
    }
    int trap2(vector<int>& height) {
        int n = height.size();
        int res = 0;
        if(n<3)return 0;
        int left = 0,right = n-1;
        int leftmax = height[left],rightmax = height[right];
        while(left<right){
            if(leftmax<rightmax){
                res += leftmax-height[left];
                left++;
                leftmax = max(leftmax,height[left]);
            }else{
                res += rightmax-height[right];
                right--;
                rightmax = max(rightmax,height[right]);
            }
        }
        return res;
    }
    int trap(vector<int>& height) {
        stack<int> s;
        int res = 0;
        if(height.size()<3)return 0;
        for(int i=0;i<height.size();i++){
            while(!s.empty()&&height[i]>height[s.top()]){
                int topidx = s.top();
                s.pop();
                while(!s.empty()&&height[topidx]==height[s.top()])
                    s.pop();
                if(!s.empty()){
                    int tmp = height[s.top()];
                    int hei = min(tmp-height[topidx],height[i]-height[topidx]);
                    int wid = i-s.top()-1;
                    res += hei*wid;
                }
            }
            s.push(i);
        }
        return res;
    }
};

int main(){
    Solution s = Solution();
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int res = s.trap(height);
    cout<<res<<endl;
    return 0;
}