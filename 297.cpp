// 297. Serialize and Deserialize Binary Tree
// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

// Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 

// Example 1:


// Input: root = [1,2,3,null,null,4,5]
// Output: [1,2,3,null,null,4,5]
// Example 2:

// Input: root = []
// Output: []
// Example 3:

// Input: root = [1]
// Output: [1]
// Example 4:

// Input: root = [1,2]
// Output: [1,2]
 

// Constraints:

// The number of nodes in the tree is in the range [0, 104].
// -1000 <= Node.val <= 1000
// 通过次数89,124提交次数161,617

#include <iostream>
#include <vector>
#include <string>
#include <list>

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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        rserialize(root, res);
        return res;
    }

    void rserialize(TreeNode* root, string& str){
        if(root==nullptr){
            str+="None,";
        }else{
            str+=to_string(root->val)+",";
            rserialize(root->left,str);
            rserialize(root->right,str);
        }
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> dataArr;
        string str;
        for(char& c:data){
            if(c==','){
                dataArr.push_back(str);
                str.clear();
            }else{
                str.push_back(c);
            }
        }
        if(!str.empty()){
            dataArr.push_back(str);
        }
        return rdeserialize(dataArr);
    }
    TreeNode* rdeserialize(list<string> &dataArr){
        if(dataArr.front()=="None"){
            dataArr.erase(dataArr.begin());
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(dataArr.front()));
        dataArr.erase(dataArr.begin());
        node->left = rdeserialize(dataArr);
        node->right = rdeserialize(dataArr);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main(){
    // vector list both ok,but list faster than vector
    Codec ser, deser;
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node3->right = node5;
    string temp = ser.serialize(node1);
    TreeNode* ans = deser.deserialize(temp);
    cout<<temp<<endl;
    cout<<ser.serialize(ans)<<endl;
    return 0;
}