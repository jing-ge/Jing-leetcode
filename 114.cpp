// 114. Flatten Binary Tree to Linked List
// Given the root of a binary tree, flatten the tree into a "linked list":

// The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 

// Example 1:


// Input: root = [1,2,5,3,4,null,6]
// Output: [1,null,2,null,3,null,4,null,5,null,6]
// Example 2:

// Input: root = []
// Output: []
// Example 3:

// Input: root = [0]
// Output: [0]
 

// Constraints:

// The number of nodes in the tree is in the range [0, 2000].
// -100 <= Node.val <= 100
 

// Follow up: Can you flatten the tree in-place (with O(1) extra space)?
// 通过次数159,345提交次数219,665

#include <iostream>
#include <vector>
#include <string>
#include <stack>

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
    void preorder(TreeNode* root,vector<TreeNode*> &tmp){
        if(root==nullptr)return;
        tmp.push_back(root);
        preorder(root->left,tmp);
        preorder(root->right,tmp);
        return ;
    }
    void flatten_1(TreeNode* root) {
        vector<TreeNode*> tmp;
        preorder(root,tmp);
        for(int i=0;i<tmp.size();i++){
            tmp[i]->left = nullptr;
            if(i>0){
                tmp[i-1]->right = tmp[i];
            }
        }
        return;
    }
    TreeNode* pre = nullptr;
    void flatten(TreeNode* root){
        if(root==nullptr)return;
        flatten(root->right);
        flatten(root->left);
        root->right = pre;
        root->left = nullptr;
        pre = root;
    }
    void flatten2(TreeNode* root){
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* pre = nullptr;
        while (!s.empty())
        {
            TreeNode* t = s.top();
            s.pop();
            if(t->right!=nullptr){
                s.push(t->right);
            }
            if(t->left!=nullptr){
                s.push(t->left);
            }
            if(pre!=nullptr){
                pre->right = t;
                pre->left = nullptr;
            }
            pre = t;
        }
        
    }
};

void print(TreeNode* head){
    while(head!=nullptr){
        cout<<head->val<<"->";
        head = head->right;
    }
    cout<<endl;
}

int main(){
    Solution s;
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    node1->left = node2;
    node1->right = node5;
    node2->left = node3;
    node2->right = node4;
    node5->right = node6;
    s.flatten2(node1);
    print(node1);
    return 0;
}