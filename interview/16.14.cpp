// 面试题 16.14. Best Line LCCI
// Given a two-dimensional graph with points on it, find a line which passes the most number of points.

// Assume all the points that passed by the line are stored in list S sorted by their number. You need to return [S[0], S[1]], that is , two points that have smallest number. If there are more than one line that passes the most number of points, choose the one that has the smallest S[0]. If there are more that one line that has the same S[0], choose the one that has smallest S[1].

// Example:

// Input:  [[0,0],[1,1],[1,0],[2,0]]
// Output:  [0,2]
// Explanation:  The numbers of points passed by the line are [0,2,3].
// Note:

// 2 <= len(Points) <= 300
// len(Points[i]) = 2
// 通过次数2,041提交次数3,936

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

void print(vector<int>&res){
    for(int &i:res){
        cout<<i<<",";
    }
    cout<<endl;
}

class Solution {
public:
    vector<int> bestLine(vector<vector<int>>& points) {

    }
};

int main(){
    Solution s = Solution();
    vector<int>points = {{0,0},{1,1},{1,0},{2,0}};
    vector<int> res = s.bestLine(points);
    print(res);
    return 0;
}