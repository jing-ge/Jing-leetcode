// 1584. Min Cost to Connect All Points
// You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

// The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

// Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

 

// Example 1:



// Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
// Output: 20
// Explanation:

// We can connect the points as shown above to get the minimum cost of 20.
// Notice that there is a unique path between every pair of points.
// Example 2:

// Input: points = [[3,12],[-2,5],[-4,1]]
// Output: 18
// Example 3:

// Input: points = [[0,0],[1,1],[1,0],[-1,1]]
// Output: 4
// Example 4:

// Input: points = [[-1000000,-1000000],[1000000,1000000]]
// Output: 4000000
// Example 5:

// Input: points = [[0,0]]
// Output: 0
 

// Constraints:

// 1 <= points.length <= 1000
// -106 <= xi, yi <= 106
// All pairs (xi, yi) are distinct.
// 通过次数6,213提交次数10,616

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class UnionFind{
public:
    vector<int> ids;
    vector<int> sizes;
    UnionFind(int n){
        ids.resize(n);
        sizes.resize(n,1);
        for(int i=0;i<n;i++)ids[i] = i;
    }
    int root(int i){
        return ids[i]==i?i:root(ids[i]);
    }
    bool merge(int i,int j){
        int p = root(i);
        int q = root(j);
        if(p!=q){
            if(sizes[p]<sizes[q]){
                ids[p] = q;
                sizes[q]+=sizes[p];
            }else{
                ids[q] = p;
                sizes[p]+=sizes[q];
            }
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int dis(vector<int>&x,vector<int>&y){
        return abs(x[0]-y[0])+abs(x[1]-y[1]);
    }
    // kruskal
    int minCostConnectPoints1(vector<vector<int>>& points) {
        vector<vector<int>> data;
        int n = points.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int d = dis(points[i],points[j]);
                data.push_back({i,j,d});
            }
        }
        sort(data.begin(),data.end(),[](vector<int>&a,vector<int>&b)->bool{return a[2]<b[2];});
        UnionFind uf = UnionFind(n);
        int res = 0;
        for(auto &t:data){
            if(uf.merge(t[0],t[1])){
                res+=t[2];
            }
        }
        return res;
    }
    //prim适合稠密图
    int prim(vector<vector<int>>& points, int start){
        int n = points.size(),res = 0;
        vector<int> lowcost(n,INT32_MAX);
        vector<int> v(n,-1);
        v[start] = 0;
        for(int i=0;i<n;i++){
            if(i==start)continue;
            lowcost[i] = dis(points[i],points[start]);
        }
        for(int i=1;i<n;i++){
            int minIdx = -1;
            int minVal = INT32_MAX;
            for(int j=0;j<n;j++){
                if(v[j]==0)continue;
                if(lowcost[j]<minVal){
                    minIdx = j;
                    minVal = lowcost[j];
                }
            }
            res+=minVal;
            v[minIdx] = 0;
            lowcost[minIdx] = -1;
            for(int j=0;j<n;j++){
                int d = dis(points[j],points[minIdx]);
                if(v[j]==-1&&d<lowcost[j]){
                    lowcost[j]=d;
                }
            }
        }
        return res;
    }
    int minCostConnectPoints(vector<vector<int>>& points){
        return prim(points,0);
    }
};

int main(){
    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    Solution s = Solution();
    int res = s.minCostConnectPoints(points);
    cout<<res<<endl;
    return 0;
}