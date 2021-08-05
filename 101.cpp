// 101. Symmetric Tree
// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

// Example 1:


// Input: root = [1,2,2,3,4,4,3]
// Output: true
// Example 2:


// Input: root = [1,2,2,null,3,null,3]
// Output: false
 

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// -100 <= Node.val <= 100
 

// Follow up: Could you solve it both recursively and iteratively?
// 通过次数372,235提交次数666,562

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

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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
    bool isSymmetric(TreeNode* root) {
        return helper2(root,root);
    }
    bool helper(TreeNode* root1,TreeNode* root2){
        if(root1==nullptr&&root2==nullptr)return true;
        if(root1==nullptr || root2==nullptr)return false;
        return (root1->val==root2->val)&&helper(root1->left,root2->right)&&helper(root1->right,root2->left); 
    }
    bool helper2(TreeNode* p,TreeNode* q){
        queue<TreeNode*> que;
        que.push(p);
        que.push(q);
        while (!que.empty())
        {
            TreeNode* tmp_p = que.front();que.pop();
            TreeNode* tmp_q = que.front();que.pop();
            if(tmp_p==nullptr&&tmp_q==nullptr)continue;
            if(tmp_p==nullptr||tmp_q==nullptr)return false;
            if(tmp_p->val!=tmp_q->val)return false;
            que.push(tmp_p->left);
            que.push(tmp_q->right);
            que.push(tmp_p->right);
            que.push(tmp_q->left);
        }
        return true;
    }
};

int main(){
    Solution s;
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(2);
    TreeNode* node4 = new TreeNode(3);
    TreeNode* node5 = new TreeNode(4);
    TreeNode* node6 = new TreeNode(4);
    TreeNode* node7 = new TreeNode(3);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    bool res = s.isSymmetric(node1);
    cout<<res<<endl;
    return 0;
}