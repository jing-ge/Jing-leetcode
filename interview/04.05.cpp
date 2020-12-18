// 面试题 04.05. Legal Binary Search Tree LCCI
// Implement a function to check if a binary tree is a binary search tree.

// Example 1:

// Input:
//     2
//    / \
//   1   3
// Output: true
// Example 2:

// Input:
//     5
//    / \
//   1   4
//      / \
//     3   6
// Output: false
// Explanation: Input: [5,1,4,null,null,3,6].
//      the value of root node is 5, but its right child has value 4.



#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int>data;
    bool isValidBST(TreeNode* root) {
        getdata(root);
        for(int i=1;i<data.size();i++){
            if(data[i]<=data[i-1])return false;
        }
        return true;
    }
    void getdata(TreeNode* root){
        if(root==nullptr)return;
        if(root->left)getdata(root->left);
        data.push_back(root->val);
        if(root->right)getdata(root->right);
    }

    bool isValidBST2(TreeNode* root) {
        return dfs(root,INT64_MIN,INT64_MAX);
    }
    bool dfs(TreeNode* root,long min,long max){
        if(root==nullptr)return true;
        if(root->val<=min||root->val>=max)return false;
        return dfs(root->left,min,root->val)&&dfs(root->right,root->val,max);
    }
};

int main(){
    Solution s = Solution();
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    node2->left = node1;
    node2->right = node3;
    bool res = s.isValidBST2(node2);
    cout<<res<<endl;
    return 0;
}