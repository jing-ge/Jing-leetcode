// 面试题 08.04. Power Set LCCIWrite a method to return all subsets of a set. The elements in a set are pairwise distinct.

// Note: The result set should not contain duplicated subsets.

// Example:

//  Input:  nums = [1,2,3]
//  Output: 
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>> &res){
    for(auto i:res){
        for(int j:i){
            cout<<j<<",";
        }
        cout<<endl;
    }
}

void print(vector<int> &res){
    for(int j:res){
        cout<<j<<",";
    }
    cout<<endl;
}

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});
        for(int n:nums){
            int s = res.size();
            for(int i=0;i<s;i++){
                vector<int>tmp(res[i]);
                tmp.push_back(n);
                // print(tmp);
                res.push_back(tmp);
            }
        }
        return res;
    }
};

int main(){
    Solution s = Solution();
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = s.subsets(nums);
    print(res);
    return 0;
}