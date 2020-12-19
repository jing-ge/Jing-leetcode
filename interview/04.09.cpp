// 面试题 04.09. BST Sequences LCCIA binary search tree was created by traversing through an array from left to right and inserting each element. Given a binary search tree with distinct elements, print all possible arrays that could have led to this tree.

// Example:
// Given the following tree:

//         2
//        / \
//       1   3
// Output:

// [
//    [2,1,3],
//    [2,3,1]
// ]

#include <iostream>
#include <vector>
#include <deque>

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
    vector<int> tmp;
    vector<vector<int>>res;
    deque<TreeNode*>q;
    vector<vector<int>> BSTSequences(TreeNode* root) {
        if(root==nullptr)return{{}};
        q.push_back(root);
        backtrace();
        return res;
    }
    void backtrace(){
        if(q.empty()){
            res.push_back(tmp);
            return;
        }
        int size = q.size();
        while(size--){
            TreeNode* t = q.front();q.pop_front();
            tmp.push_back(t->val);
            int children = 0;
            if(t->left){
                children++;
                q.push_back(t->left);
            }
            if(t->right){
                children++;
                q.push_back(t->right);
            }
            backtrace();
            while(children--){
                q.pop_back();
            }
            q.push_back(t);
            tmp.pop_back();
        }
    }
    
};
void print(vector<vector<int>>& res){
    for(auto t:res){
        for(int i:t){
            cout<<i<<",";
        }
        cout<<endl;
    }
}
int main(){
    TreeNode * node1 = new TreeNode(1);
    TreeNode * node2 = new TreeNode(2);
    TreeNode * node3 = new TreeNode(3);
    node2->left = node1;
    node2->right = node3;
    Solution s = Solution();
    vector<vector<int>> res = s.BSTSequences(node2);
    print(res);
    return 0;
}