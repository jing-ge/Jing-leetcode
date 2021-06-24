// 149. Max Points on a Line
// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

 

// Example 1:


// Input: points = [[1,1],[2,2],[3,3]]
// Output: 3
// Example 2:


// Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
// Output: 4
 

// Constraints:

// 1 <= points.length <= 300
// points[i].length == 2
// -104 <= xi, yi <= 104
// All the points are unique.
// 通过次数38,012提交次数120,085

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int gcd(int a,int b){
        return b?gcd(b,a%b):a;
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n<=2)return n;
        int res = 0;
        for(int i=0;i<n;i++){
            if(res >n-i ||res>n/2){
                break;
            }
            unordered_map<int,int> mp;
            for(int j=i+1;j<n;j++){
                int dx = points[i][0]-points[j][0];
                int dy = points[i][1] - points[j][1];
                if(dx==0){
                    dy = 1;
                }else if(dy==0){
                    dx = 1;
                }else{
                    if(dy<0){
                        dx = -dx;
                        dy = -dy;
                    }
                    int g = gcd(dx,dy);
                    dx /= g;
                    dy /= g;
                }
                mp[dy+(20000+1)*dx]++;
            }
            int maxn = 0;
            for(auto& t:mp){
                maxn = max(maxn,t.second+1);
            }
            res = max(res,maxn);
        }
        return res;

    }
};

int main(){
    Solution s;
    vector<vector<int>> points = {{1,1},{2,2},{3,3}};
    int res = s.maxPoints(points);
    cout<<res<<endl;
    points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    res = s.maxPoints(points);
    cout<<res<<endl;
    return 0;
}