// 1232. Check If It Is a Straight Line
// You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

 

 

// Example 1:



// Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
// Output: true
// Example 2:



// Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
// Output: false
 

// Constraints:

// 2 <= coordinates.length <= 1000
// coordinates[i].length == 2
// -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
// coordinates contains no duplicate point.
// 通过次数12,544提交次数26,384

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int chax = coordinates[0][0]-coordinates[1][0],chay = coordinates[0][1]-coordinates[1][1];
        for(int i=2;i<coordinates.size();i++){
            if(chax*(coordinates[i][1]-coordinates[0][1])!=chay*(coordinates[i][0]-coordinates[0][0]))return false;
        }
        return true;
    }
};

int main(){
    vector<vector<int>> nums = {{1,2},{2,3},{3,4},{4,5},{5,6}};
    Solution s = Solution();
    bool res = s.checkStraightLine(nums);
    cout<<res<<endl;
    return 0;
}