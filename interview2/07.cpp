// 剑指 Offer 07. 重建二叉树
// 输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。

// 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

 

// 示例 1:


// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]
// 示例 2:

// Input: preorder = [-1], inorder = [-1]
// Output: [-1]
 

// 限制：

// 0 <= 节点个数 <= 5000

 

// 注意：本题与主站 105 题重复：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

// 通过次数161,835提交次数233,060

#include <iostream>
#include <vector>
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
    unordered_map<int,int> map;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0)return nullptr;
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]] = i;
        }
        return mybuild(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
    TreeNode* mybuild(vector<int> &preorder,vector<int> &inorder,int prel,int prer,int inl,int inr){
        if(prel>prer)return nullptr;
        int t = preorder[prel];
        int idx = map[t];
        TreeNode* root = new TreeNode(t);
        root->left = mybuild(preorder,inorder,prel+1,prel+idx-inl,inl,idx-1);
        root->right = mybuild(preorder,inorder,prel+idx-inl+1,prer,idx+1,inr);
        return root;
    }
};
int main(){
    Solution s;
    vector<int> preorder = {3,9,20,15,7},inorder = {9,3,15,20,7};
    TreeNode* root = s.buildTree(preorder,inorder);
    return 0;
}