// 面试题 17.12. BiNode
// 二叉树数据结构TreeNode可用来表示单向链表（其中left置空，right为下一个链表节点）。实现一个方法，把二叉搜索树转换为单向链表，要求依然符合二叉搜索树的性质，转换操作应是原址的，也就是在原始的二叉搜索树上直接修改。

// 返回转换后的单向链表的头节点。

// 注意：本题相对原题稍作改动

 

// 示例：

// 输入： [4,2,5,1,3,null,6,0]
// 输出： [0,null,1,null,2,null,3,null,4,null,5,null,6]
// 提示：

// 节点数量不会超过 100000。

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
    TreeNode* head = new TreeNode(-1);
    TreeNode* prev = nullptr;
    TreeNode* convertBiNode(TreeNode* root) {
        helper(root);
        return head->right;
    }
    void helper(TreeNode *root){
        if(root == nullptr)return;
        helper(root->left);
        if(prev == nullptr){
            prev = root;
            head->right = root;
        }else{
            prev->right = root;
            prev = root;
        }
        root->left = nullptr;
        helper(root->right);
    }
    void preorder(TreeNode* root){
        if(root==nullptr)return;
        preorder(root->left);
        cout<<root->val<<",";
        preorder(root->right);
    }
    void print(TreeNode* root){
        TreeNode* tmp = root;
        while (tmp!=nullptr)
        {
            cout<<tmp->val<<"->";
            tmp = tmp->right;
        }
        
    }
};

int main(){
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node0 = new TreeNode(0);
    node4->left = node2;node4->right = node5;
    node2->left = node1;node2->right = node3;
    node5->right = node6;
    node1->left = node0;
    Solution s = Solution();
    s.preorder(node4);
    cout<<endl;
    TreeNode* t = s.convertBiNode(node4);
    s.print(t);
    cout<<endl;
    return 0;

}