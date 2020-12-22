// 103. Binary Tree Zigzag Level Order TraversalGiven a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
// ]


#include <iostream>
#include <queue>

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

void print(vector<vector<int>> &res){
    for(auto i:res){
        for(int j:i){
            cout<<j<<",";
        }
        cout<<endl;
    }
}

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root == nullptr)return res;
        queue<TreeNode*> q;
        q.push(root);
        int st = 1;
        bool flag = true;
        while(!q.empty()){
            int s = q.size();
            vector<int>tmp(s);
            int idx = flag?0:s-1; 
            while(s--){
                if(flag){
                    tmp[idx++] = q.front()->val;
                    if(q.front()->left)q.push(q.front()->left);
                    if(q.front()->right)q.push(q.front()->right);
                    q.pop();
                }else{
                    tmp[idx--] = q.front()->val;
                    if(q.front()->left)q.push(q.front()->left);
                    if(q.front()->right)q.push(q.front()->right);
                    q.pop();
                }
            }
            flag = !flag;
            res.push_back(tmp);
        }
        return res;
    }
};

int main(){
    TreeNode* node1 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(9);
    TreeNode* node3 = new TreeNode(20);
    TreeNode* node4 = new TreeNode(15);
    TreeNode* node5 = new TreeNode(7);
    node1->left = node2;node1->right = node3;
    node3->left = node4;node3->right = node5;
    Solution s = Solution();
    vector<vector<int>> res = s.zigzagLevelOrder(node1);
    print(res);
    return 0;
}