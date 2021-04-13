// 783. Minimum Distance Between BST Nodes
// Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

// Note: This question is the same as 530: https://leetcode.com/problems/minimum-absolute-difference-in-bst/

 

// Example 1:


// Input: root = [4,2,6,1,3]
// Output: 1
// Example 2:


// Input: root = [1,0,48,null,null,12,49]
// Output: 1
 

// Constraints:

// The number of nodes in the tree is in the range [2, 100].
// 0 <= Node.val <= 105
// 通过次数30,659提交次数53,804

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int prev,res;
    void dfs(TreeNode* root){
        if(root==nullptr)return;
        dfs(root->left);
        if(prev==-1)prev = root->val;
        else{
            res = min(res,root->val-prev);
            prev = root->val;
        }
        dfs(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        prev = -1;
        res = INT32_MAX;
        dfs(root);
        return res;
    }
};

int main(){
    TreeNode* node1 = new TreeNode(4);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(6);
    TreeNode* node4 = new TreeNode(1);
    TreeNode* node5 = new TreeNode(3);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    Solution s;
    int res = s.minDiffInBST(node1);
    cout<<res<<endl;
    return 0;
}