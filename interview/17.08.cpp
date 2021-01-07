// 面试题 17.08. Circus Tower LCCI
// A circus is designing a tower routine consisting of people standing atop one anoth­er's shoulders. For practical and aesthetic reasons, each person must be both shorter and lighter than the person below him or her. Given the heights and weights of each person in the circus, write a method to compute the largest possible number of people in such a tower.

// Example:

// Input: height = [65,70,56,75,60,68] weight = [100,150,90,190,95,110]
// Output: 6
// Explanation: The longest tower is length 6 and includes from top to bottom: (56,90), (60,95), (65,100), (68,110), (70,150), (75,190)
// Note:

// height.length == weight.length <= 10000

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        vector<pair<int,int>> tmp;
        for(int i=0;i<height.size();i++)tmp.push_back({height[i],weight[i]});
        sort(tmp.begin(),tmp.end(),[](const pair<int,int> &a,const pair<int,int> &b){
            return a.first==b.first?a.second>b.second:a.first<b.first;
        });
        vector<int>dp;
        for(const auto&[h,w]:tmp){
            auto p = lower_bound(dp.begin(),dp.end(),w);
            if(p==dp.end())dp.push_back(w);
            else *p = w;
        }
        return dp.size();
    }
};

int main(){
    Solution s = Solution();
    vector<int> height = {65,70,56,75,60,68},weight = {100,150,90,190,95,110};
    s.bestSeqAtIndex
    return 0;
}