// 671. Second Minimum Node In a Binary Tree
// Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. More formally, the property root.val = min(root.left.val, root.right.val) always holds.

// Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

// If no such second minimum value exists, output -1 instead.

 

 

// Example 1:


// Input: root = [2,2,5,null,null,5,7]
// Output: 5
// Explanation: The smallest value is 2, the second smallest value is 5.
// Example 2:


// Input: root = [2,2,2]
// Output: -1
// Explanation: The smallest value is 2, but there isn't any second smallest value.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 25].
// 1 <= Node.val <= 231 - 1
// root.val == min(root.left.val, root.right.val) for each internal node of the tree.
// 通过次数34,604提交次数73,375

#include <iostream>
#include <vector>
#include <string>

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
    int res;
    int rootval;
    int findSecondMinimumValue(TreeNode* root) {
        if(root==nullptr)return -1;
        res = -1;
        rootval = root->val;
        dfs(root->left);
        dfs(root->right);
        return res;
    }

    void dfs(TreeNode* root){
        if(root==nullptr)return ;
        if(res!=-1&&root->val>=res)return;
        if(root->val>rootval){
            res = root->val;
        }
        dfs(root->left);
        dfs(root->right);
    }
};

int main(){
    Solution s;
    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(2);
    TreeNode* node4 = new TreeNode(5);
    TreeNode* node5 = new TreeNode(7);
    node1->left = node2;
    node1->right = node3;
    // node3->left = node4;
    // node3->right = node5;
    int res = s.findSecondMinimumValue(node1);
    cout<<res<<endl;
    return 0;
}