// 面试题 04.02. Minimum Height Tree LCCI
// Given a sorted (increasing order) array with unique integer elements, write an algo­rithm to create a binary search tree with minimal height.

// Example:

// Given sorted array: [-10,-3,0,5,9],

// One possible answer is: [0,-3,9,-10,null,5]，which represents the following tree: 

//           0 
//          / \ 
//        -3   9 
//        /   / 
//      -10  5 


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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree2(nums,0,nums.size()-1);
    }
    TreeNode* buildTree(vector<int>&nums){
        if(nums.size()==0)return nullptr;
        int mid = nums.size()/2;
        vector<int> left(nums.begin(),nums.begin()+mid);
        vector<int> right(nums.begin()+mid+1,nums.end());
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = buildTree(left);
        node->right = buildTree(right);
        return node;
    }
    TreeNode* buildTree2(vector<int>&nums,int l,int r){
        if(l>r)return nullptr;
        if(l==r)return new TreeNode(nums[l]);
        int mid = (l+r)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = buildTree2(nums,l,mid-1);
        node->right = buildTree2(nums,mid+1,r);
        return node;
    }

    void print(TreeNode* node){
        if(node == nullptr)return;
        cout<<node->val<<endl;
        print(node->left);
        print(node->right);
    }
};
int main(){
    vector<int> nums = {-10,-3,0,5,9};
    Solution s = Solution();
    TreeNode* res = s.sortedArrayToBST(nums);
    s.print(res);
    return 0;
}