// 面试题 04.06. Successor LCCI
// Write an algorithm to find the "next" node (i.e., in-order successor) of a given node in a binary search tree.

// Return null if there's no "next" node for the given node.

// Example 1:

// Input: root = [2,1,3], p = 1

//   2
//  / \
// 1   3

// Output: 2
// Example 2:

// Input: root = [5,3,6,2,4,null,null,1], p = 6

//       5
//      / \
//     3   6
//    / \
//   2   4
//  /   
// 1

// Output: null


#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*>data;
    TreeNode* inorderSuccessor2(TreeNode* root, TreeNode* p) {
        midorder(root);
        int i=0;
        for(;i<data.size();i++){
            if(data[i]==p){
                return (i+1)>=data.size()?nullptr:data[i+1];
            }
        }
    }
    void midorder(TreeNode* root){
        if(root==nullptr)return;
        midorder(root->left);
        data.push_back(root);
        midorder(root->right);
        return;
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root==nullptr||p==nullptr)return nullptr;
        if(p->val>=root->val){
            return inorderSuccessor(root->right,p);
        }else{
            TreeNode* node = inorderSuccessor(root->left,p);
            return node?node:root;
        }
    }
};

int main(){
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    node2->left = node1;
    node2->right = node3;
    Solution s = Solution();
    TreeNode* res = s.inorderSuccessor(node2,node1);
    cout<<res->val<<endl;
    return 0;
}