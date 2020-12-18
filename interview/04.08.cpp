// 面试题 04.08. First Common Ancestor LCCI
// Design an algorithm and write code to find the first common ancestor of two nodes in a binary tree. Avoid storing additional nodes in a data structure. NOTE: This is not necessarily a binary search tree.

// For example, Given the following tree: root = [3,5,1,6,2,0,8,null,null,7,4]

//     3
//    / \
//   5   1
//  / \ / \
// 6  2 0  8
//   / \
//  7   4
// Example 1:

// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// Input: 3
// Explanation: The first common ancestor of node 5 and node 1 is node 3.
// Example 2:

// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
// Output: 5
// Explanation: The first common ancestor of node 5 and node 4 is node 5.
// Notes:

// All node values are pairwise distinct.
// p, q are different node and both can be found in the given tree.


#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr)return nullptr;
        if(root==p||root==q)return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(left!=nullptr&&right!=nullptr)return root;
        return left?left:right;
    }
};

int main(){
    Solution s = Solution();
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node0 = new TreeNode(0);
    TreeNode* node8 = new TreeNode(8);
    TreeNode* node7 = new TreeNode(2);
    TreeNode* node4 = new TreeNode(4);
    node3->left = node5;node3->right = node1;
    node5->left = node6;node6->right = node2;
    node1->left = node0;node1->right = node8;
    node2->left = node7;node2->right = node4;
    TreeNode* res = s.lowestCommonAncestor(node3,node5,node1);
    cout<<res->val<<endl;
    return 0;
}