// 971. Flip Binary Tree To Match Preorder Traversal
// You are given the root of a binary tree with n nodes, each node has a different value from 1 to n. You are also given a sequence of n values voyage, reported by a preorder traversal starting from the root.

// A node in this binary tree can be flipped by swapping its left child and its right child.

// Flip the least number of nodes in the tree so that the preorder traversal of the tree matches voyage.

// Return a list of the values of all nodes flipped. You may return the answer in any order. If we cannot flip the nodes in the tree to obtain voyage, return the list [-1].

// The preorder traversal of a node means we report the current node's value, then preorder-traverse the left child, then preorder-traverse the right child.

 

// Example 1:


// Input: root = [1,2], voyage = [2,1]
// Output: [-1]
// Example 2:


// Input: root = [1,2,3], voyage = [1,3,2]
// Output: [1]
// Example 3:


// Input: root = [1,2,3], voyage = [1,2,3]
// Output: []
 

// Constraints:

// The number of nodes in the tree is n.
// n == voyage.length
// 1 <= n <= 100
// 1 <= Node.val, voyage[i] <= n
// All the values of the tree are unique.
// All the values of voyage are unique.
// 通过次数4,416提交次数9,768
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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if(dfs(root,voyage))return res;
        return {-1};
    }
    int i=0;
    vector<int> res;
    
    bool dfs(TreeNode* root,vector<int>& voyage){
        if(root==nullptr)return true;
        if(i>voyage.size())return false;

        if(root->val!=voyage[i])return false;
        i++;
        if(dfs(root->left,voyage)&&dfs(root->right,voyage))return true;
        if(dfs(root->right,voyage)&&dfs(root->left,voyage)){
            res.push_back(root->val);
            return true;
        }
        return false;
    }
};

int main(){
    Solution s;
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    node1->left = node2;
    node1->right = node3;
    vector<int> voyage = {1,3,2};
    vector<int> res = s.flipMatchVoyage(node1,voyage);
    for(int i:res)cout<<i<<",";
    cout<<endl; 
    return 0;
}