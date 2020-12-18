// 面试题 04.03. List of Depth LCCI
// Given a binary tree, design an algorithm which creates a linked list of all the nodes at each depth (e.g., if you have a tree with depth D, you'll have D linked lists). Return a array containing all the linked lists.

//  

// Example:

// Input: [1,2,3,4,5,null,7,8]

//         1
//        /  \ 
//       2    3
//      / \    \ 
//     4   5    7
//    /
//   8

// Output: [[1],[2,3],[4,5,7],[8]]


#include <iostream>
#include <vector>
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print(vector<ListNode*> res){
    for(auto head:res){
        while(head){
            cout<<head->val<<"->";
            head = head->next;
        }
        cout<<endl;
    }
}

class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        return tolist(tree);
    }

    vector<ListNode*> tolist(TreeNode* tree){
        vector<ListNode*> res;
        queue<TreeNode*> q;
        q.push(tree);
        while(!q.empty()){
            queue<TreeNode*>t;
            t.swap(q);
            ListNode* head = new ListNode(0);
            ListNode* tnode = head;
            while(!t.empty()){
                TreeNode* tmp = t.front();
                tnode->next = new ListNode(tmp->val);
                tnode = tnode->next;
                t.pop();
                if(tmp->left){
                    q.push(tmp->left);
                }
                if(tmp->right){
                    q.push(tmp->right);
                }
            }
            res.push_back(head->next);
            delete head;
        }
        return res;
    }
};

int main(){
    Solution s = Solution();
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node8 = new TreeNode(8);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->right = node7;
    node4->left = node8;
    vector<ListNode*> res = s.listOfDepth(node1);
    print(res);
    return 0;
}