// 959. Regions Cut By Slashes
// In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a /, \, or blank space.  These characters divide the square into contiguous regions.

// (Note that backslash characters are escaped, so a \ is represented as "\\".)

// Return the number of regions.

 

// Example 1:

// Input:
// [
//   " /",
//   "/ "
// ]
// Output: 2
// Explanation: The 2x2 grid is as follows:

// Example 2:

// Input:
// [
//   " /",
//   "  "
// ]
// Output: 1
// Explanation: The 2x2 grid is as follows:

// Example 3:

// Input:
// [
//   "\\/",
//   "/\\"
// ]
// Output: 4
// Explanation: (Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.)
// The 2x2 grid is as follows:

// Example 4:

// Input:
// [
//   "/\\",
//   "\\/"
// ]
// Output: 5
// Explanation: (Recall that because \ characters are escaped, "/\\" refers to /\, and "\\/" refers to \/.)
// The 2x2 grid is as follows:

// Example 5:

// Input:
// [
//   "//",
//   "/ "
// ]
// Output: 3
// Explanation: The 2x2 grid is as follows:

 

// Note:

// 1 <= grid.length == grid[0].length <= 30
// grid[i][j] is either '/', '\', or ' '.
// 通过次数5,391提交次数7,634
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class UnionFind{
public:
    vector<int> parent;
    vector<int> size;
    int n;
    UnionFind(int _n){
        n = _n;
        for(int i=0;i<n;i++){
            parent.push_back(i);
            size.push_back(1);
        }
    }
    int root(int i){
        return parent[i]==i?i:root(parent[i]);
    }
    bool merge(int i, int j){
        // cout<<"merge:"<<i<<","<<j<<endl;
        i = root(i);
        j = root(j);
        if(i==j)return false;
        if(size[i]>size[j]){
            parent[j] = i;
            size[i] += size[j];
        }else{
            parent[i] = j;
            size[j] += size[i];
        }
        n--;
        return true;
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size()*grid.size()*4;
        UnionFind uf(n);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                char c = grid[i][j];
                int t = grid.size()*i+j;
                // cout<<c<<":"<<t<<endl;
                if(c==' '){
                    uf.merge(4*t,4*t+1);
                    uf.merge(4*t+1,4*t+2);
                    uf.merge(4*t+2,4*t+3);
                    uf.merge(4*t+3,4*t);
                }else if(c=='/'){
                    uf.merge(4*t+1,4*t+2);
                    uf.merge(4*t+3,4*t);
                }else{
                    uf.merge(4*t,4*t+1);
                    uf.merge(4*t+2,4*t+3);
                }
                if(j+1<grid.size()){
                    uf.merge(4*t+1,4*(t+1)+3);
                }
                if(i+1<grid.size()){
                    uf.merge(4*t+2,4*(t+grid.size()));
                }
            }
        }
        return uf.n;
    }
};

int main(){
    Solution s;
    vector<string> grid = {"//",
  "/ "};
    int res = s.regionsBySlashes(grid);
    cout<<res<<endl;
    return 0;
}