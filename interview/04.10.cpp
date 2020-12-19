// 面试题 04.10. Check SubTree LCCIT1 and T2 are two very large binary trees, with T1 much bigger than T2. Create an algorithm to determine if T2 is a subtree of T1.

// A tree T2 is a subtree of T1 if there exists a node n in T1 such that the subtree of n is identical to T2. That is, if you cut off the tree at node n, the two trees would be identical.

// Example1:

//  Input: t1 = [1, 2, 3], t2 = [2]
//  Output: true
// Example2:

//  Input: t1 = [1, null, 2, 4], t2 = [3, 2]
//  Output: false
// Note:

// The node numbers of both tree are in [0, 20000].


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
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if(t2==nullptr)return true;
        if(t1==nullptr)return false;
        return isSame(t1,t2)||checkSubTree(t1->left,t2)||checkSubTree(t1->right,t2);
    }
    bool isSame(TreeNode* t1, TreeNode* t2) {
        if(t1==nullptr&&t2==nullptr)return true;
        if(t1==nullptr||t2==nullptr)return false;
        return (t1->val==t2->val)&&isSame(t1->left,t2->left)&&isSame(t1->right,t2->right);
    }
};

int main(){
    TreeNode * node1 = new TreeNode(1);
    TreeNode * node2 = new TreeNode(2);
    TreeNode * node3 = new TreeNode(3);
    TreeNode * node4 = new TreeNode(2);
    node1->left = node2;node1->right = node3;
    Solution s =Solution();
    bool res = s.checkSubTree(node1,node4);
    cout<<res<<endl;
    return 0;
}
