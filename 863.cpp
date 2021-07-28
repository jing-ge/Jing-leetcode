// 863. All Nodes Distance K in Binary Tree
// Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

// You can return the answer in any order.

 

// Example 1:


// Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
// Output: [7,4,1]
// Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
// Example 2:

// Input: root = [1], target = 1, k = 3
// Output: []
 

// Constraints:

// The number of nodes in the tree is in the range [1, 500].
// 0 <= Node.val <= 500
// All the values Node.val are unique.
// target is the value of one of the nodes in the tree.
// 0 <= k <= 1000
// 通过次数25,860提交次数44,056

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

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
    unordered_map<TreeNode*,TreeNode*> map;
    int K;
    vector<int> res;
    void getparents(TreeNode* root){
        if(root->left!=nullptr){
            map[root->left] = root;
            getparents(root->left);
        }
        if(root->right!=nullptr){
            map[root->right] = root;
            getparents(root->right);
        }
    }
    void dfs(TreeNode* node,TreeNode* from, int k){
        if(node==nullptr)return;
        if(k==K){
            res.push_back(node->val);
        }
        if(node->left!=from)
        dfs(node->left,node,k+1);
        if(node->right!=from)
        dfs(node->right,node,k+1);
        if(map[node]!=from)
        dfs(map[node],node,k+1);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        K = k;
        getparents(root);
        dfs(target,nullptr,0);
        return res;
    }
};

int main(){
    Solution s;
    TreeNode* node1 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(5);
    TreeNode* node3 = new TreeNode(1);
    TreeNode* node4 = new TreeNode(6);
    TreeNode* node5 = new TreeNode(2);
    TreeNode* node6 = new TreeNode(0);
    TreeNode* node7 = new TreeNode(8);
    TreeNode* node8 = new TreeNode(7);
    TreeNode* node9 = new TreeNode(4);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    node5->left = node8;
    node5->right = node9;
    TreeNode* target = node2;
    int k = 2;
    vector<int> res = s.distanceK(node1,target,k);
    for(int i:res)cout<<i<<",";
    cout<<endl;
    return 0;

}