// 面试题 04.04. Check Balance LCCI
// Implement a function to check if a binary tree is balanced. For the purposes of this question, a balanced tree is defined to be a tree such that the heights of the two subtrees of any node never differ by more than one.


// Example 1:

// Given tree [3,9,20,null,null,15,7]
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return true.
// Example 2:

// Given [1,2,2,3,3,null,null,4,4]
//       1
//      / \
//     2   2
//    / \
//   3   3
//  / \
// 4   4
// return false.

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
    bool isBalanced(TreeNode* root) {
        if (root==nullptr)return true;
        int cha = deepth(root->left)-deepth(root->right);
        bool res = cha<=1&&cha>=-1;
        return res&&isBalanced(root->left)&&isBalanced(root->right);
    }
    int deepth(TreeNode* root){
        if(root==nullptr)return 0;
        return max(deepth(root->left),deepth(root->right))+1;
    }

    bool isbalacnde = true;
    bool isBalanced1(TreeNode* root) {
        deepth1(root);
        return isbalacnde;
    }
    int deepth1(TreeNode* root){
        if(root==nullptr||!isbalacnde)return 0;
        int left = deepth1(root->left);
        int right = deepth1(root->right);
        if((left-right)>1||(right-left)>1)isbalacnde = false;
        return max(left,right)+1;
    }

};

int main(){
    Solution s = Solution();
    TreeNode* node1 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(9);
    TreeNode* node3 = new TreeNode(20);
    TreeNode* node4 = new TreeNode(15);
    TreeNode* node5 = new TreeNode(7);
    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node3->right = node5;
    bool res = s.isBalanced1(node1);
    cout<<res<<endl;
    return 0;
}