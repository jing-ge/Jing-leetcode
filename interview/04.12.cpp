// 面试题 04.12. Paths with Sum LCCI
// You are given a binary tree in which each node contains an integer value (which might be positive or negative). Design an algorithm to count the number of paths that sum to a given value. The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

// Example:
// Given the following tree and  sum = 22,

//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1
// Output:

// 3
// Explanation: Paths that have sum 22 are: [5,4,11,2], [5,8,4,5], [4,11,7]
// Note:

// node number <= 10000


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
    int count = 0;
    int pathSum(TreeNode* root, int sum) {
        preorder(root,sum);
        return count;
    }
    void preorder(TreeNode* root,int sum) {
        if(root==nullptr)return;
        dfs(root,sum);
        preorder(root->left,sum);
        preorder(root->right,sum);
    }
    void dfs(TreeNode* root,int sum){
        if(root==nullptr)return ;
        if(root->val==sum){
            count++;
        }
        dfs(root->left,sum-root->val);
        dfs(root->right,sum-root->val);
    }
};

int main(){
    TreeNode* node1 = new TreeNode(5);
    TreeNode* node2 = new TreeNode(4);
    TreeNode* node3 = new TreeNode(8);
    TreeNode* node4 = new TreeNode(11);
    TreeNode* node5 = new TreeNode(13);
    TreeNode* node6 = new TreeNode(4);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node8 = new TreeNode(2);
    TreeNode* node9 = new TreeNode(5);
    TreeNode* node10 = new TreeNode(1);
    node1->left = node2;node1->right = node3;
    node2->left = node4;
    node3->left = node5;node3->right = node6;
    node4->left = node7;node4->right = node8;
    node6->left = node9;node6->right = node10;
    Solution s = Solution();
    int res = s.pathSum(node1,22);
    cout<<res<<endl;
    return 0;
}