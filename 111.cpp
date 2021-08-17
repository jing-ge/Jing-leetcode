// 111. Minimum Depth of Binary Tree
// Given a binary tree, find its minimum depth.

// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

// Note: A leaf is a node with no children.

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: 2
// Example 2:

// Input: root = [2,null,3,null,4,null,5,null,6]
// Output: 5
 

// Constraints:

// The number of nodes in the tree is in the range [0, 105].
// -1000 <= Node.val <= 1000
// 通过次数252,285提交次数521,823

#include <iostream>
#include <vector>
#include <string>
#include <queue>

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
    int minDepth(TreeNode* root) {
        if(root==nullptr)return 0;
        queue<TreeNode*> q;
        q.push(root);
        int res = 1;
        while (!q.empty())
        {
            int t = q.size();
            for(int i=0;i<t;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left==nullptr&&node->right==nullptr)return res;
                if(node->left!=nullptr)q.push(node->left);
                if(node->right!=nullptr)q.push(node->right);
            }      
            res++;
        }
        return res;
    }
};

int main(){
    Solution s;
    TreeNode* node1 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(9);
    TreeNode* node3 = new TreeNode(20);
    TreeNode* node4 = new TreeNode(15);
    TreeNode* node5 = new TreeNode(7);
    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node3->right = node5;
    int res = s.minDepth(node1);
    cout<<res<<endl;
    return 0;
}