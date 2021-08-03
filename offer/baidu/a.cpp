//leetcode 114

#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
};

// void preorder(Node* root,vector<Node*>& tmp){
//     if(root==nullptr)return ;
//     tmp.push_back(root);
//     preorder(tmp->left,tmp);
//     preorder(tmp->right,tmp)
// }

Node* trans2(Node*root){
    if(root==nullptr)return root;
    root->left = trans2(root->left);
    root->left->left = trans2(root->right);
    root->right = nullptr;
    return root;
}

// Node* trans(Node* root){
//     vector<Node*> tmp;
//     preorder(root,tmp);
//     for(int i=0;i<tmp.size();i++){
//         tmp[i]->left = nullptr;
//         tmp[i]->right = nullptr;
//     }
//     for(int i=1;i<tmp.size();i++){
//         tmp[i-1]->left = tmp[i];
//     }
//     return tmp[0];
// }

int main(){
}
