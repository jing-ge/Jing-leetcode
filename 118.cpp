// Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


// In Pascal's triangle, each number is the sum of the two numbers directly above it.

// Example:

// Input: 5
// Output:
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=0;i<numRows;i++){
            vector<int> tmp;
            for(int j=0;j<=i;j++){
                if(j==0||j==i){
                    tmp.push_back(1);
                }else{
                    tmp.push_back(res[i-1][j-1]+res[i-1][j]);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};

int main() {
    int num = 5;
    Solution s = Solution();
    vector<vector<int>> res = s.generate(num);
    for(auto& v:res){
        for(int& i:v)
            cout<<i<<",";
        cout<<endl;
    } 
}