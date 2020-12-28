// 面试题 16.11. Diving Board LCCI
// You are building a diving board by placing a bunch of planks of wood end-to-end. There are two types of planks, one of length shorter and one of length longer. You must use exactly K planks of wood. Write a method to generate all possible lengths for the diving board.

// return all lengths in non-decreasing order.

// Example:

// Input: 
// shorter = 1
// longer = 2
// k = 3
// Output:  {3,4,5,6}
// Note:

// 0 < shorter <= longer
// 0 <= k <= 100000
// 通过次数42,414提交次数95,929

#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>&res){
    for(int&i:res){
        cout<<i<<",";
    }
    cout<<endl;
}

class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int>res;
        for(int i=0;i<=k;i++){
            res.push_back(shorter*(k-i)+longer*i);
        }
        return res;
    }
};

int main(){
    Solution s = Solution();
    vector<int>res = s.divingBoard(1,2,3);
    print(res);
    return 0;
}