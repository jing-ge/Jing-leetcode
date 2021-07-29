// 1104. Path In Zigzag Labelled Binary Tree
// In an infinite binary tree where every node has two children, the nodes are labelled in row order.

// In the odd numbered rows (ie., the first, third, fifth,...), the labelling is left to right, while in the even numbered rows (second, fourth, sixth,...), the labelling is right to left.



// Given the label of a node in this tree, return the labels in the path from the root of the tree to the node with that label.

 

// Example 1:

// Input: label = 14
// Output: [1,3,4,14]
// Example 2:

// Input: label = 26
// Output: [1,2,6,10,26]
 

// Constraints:

// 1 <= label <= 10^6
// 通过次数23,117提交次数30,404

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int getReverse(int label,int row){
        return (1<<row-1)+(1<<row)-1-label;
    }
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        int row =1,rowstart = 1;
        while (rowstart*2<=label)  
        {
            rowstart*=2;
            row++;
        }
        if(row%2==0){
            label = getReverse(label,row);
        }
        while (row>0)
        {
            if(row%2==0)res.push_back(getReverse(label,row));
            else res.push_back(label);
            row--;
            label = label>>1;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

int main(){
    Solution s;
    int label = 14;
    vector<int> res = s.pathInZigZagTree(label);
    for(int i:res)cout<<i<<",";cout<<endl;
    return 0;
}