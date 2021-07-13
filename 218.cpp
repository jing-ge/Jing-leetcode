// 218. The Skyline Problem
// A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Given the locations and heights of all the buildings, return the skyline formed by these buildings collectively.

// The geometric information of each building is given in the array buildings where buildings[i] = [lefti, righti, heighti]:

// lefti is the x coordinate of the left edge of the ith building.
// righti is the x coordinate of the right edge of the ith building.
// heighti is the height of the ith building.
// You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

// The skyline should be represented as a list of "key points" sorted by their x-coordinate in the form [[x1,y1],[x2,y2],...]. Each key point is the left endpoint of some horizontal segment in the skyline except the last point in the list, which always has a y-coordinate 0 and is used to mark the skyline's termination where the rightmost building ends. Any ground between the leftmost and rightmost buildings should be part of the skyline's contour.

// Note: There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...,[2 3],[4 5],[7 5],[11 5],[12 7],...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...,[2 3],[4 5],[12 7],...]

 

// Example 1:


// Input: buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
// Output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
// Explanation:
// Figure A shows the buildings of the input.
// Figure B shows the skyline formed by those buildings. The red points in figure B represent the key points in the output list.
// Example 2:

// Input: buildings = [[0,2,3],[2,5,3]]
// Output: [[0,3],[5,0]]
 

// Constraints:

// 1 <= buildings.length <= 104
// 0 <= lefti < righti <= 231 - 1
// 1 <= heighti <= 231 - 1
// buildings is sorted by lefti in non-decreasing order.
// 通过次数25,825提交次数48,644

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

void print(vector<vector<int>> &data){
    for(auto &t:data){
        for(int &i:t){
            cout<<i<<",";
        }
        cout<<endl;
    }
}

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        auto cmp = [](const pair<int,int> &a,const pair<int,int> &b){return a.second<b.second;};
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> que(cmp);
        vector<int> boundaries;
        for (auto& building : buildings) {
            boundaries.emplace_back(building[0]);
            boundaries.emplace_back(building[1]);
        }
        sort(boundaries.begin(), boundaries.end());
        vector<vector<int>> res;
        int n = buildings.size(),idx = 0;
        for(int boundary:boundaries){
            while (idx<n && buildings[idx][0]<=boundary)
            {
                que.emplace(buildings[idx][1],buildings[idx][2]);
                idx++;
            }
            while (!que.empty()&&que.top().first<=boundary)
            {
                que.pop();
            }
            int maxn = que.empty()?0:que.top().second;
            if(res.size()==0||maxn!=res.back()[1])res.push_back({boundary,maxn});
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> buildings = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    vector<vector<int>> res = s.getSkyline(buildings);
    print(res);
    return 0;
}