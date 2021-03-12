// 331. Verify Preorder Serialization of a Binary Tree
// One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

//      _9_
//     /   \
//    3     2
//   / \   / \
//  4   1  #  6
// / \ / \   / \
// # # # #   # #
// For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

// Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

// Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

// You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

// Example 1:

// Input: "9,3,4,#,#,1,#,#,2,#,6,#,#"
// Output: true
// Example 2:

// Input: "1,#"
// Output: false
// Example 3:

// Input: "9,#,#,1"
// Output: false
// 通过次数16,259提交次数34,315

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int res = 1;
        for(int i=0;i<preorder.size();i++){
            if(res==0)return false;
            if(preorder[i]==',')continue;
            else if(preorder[i]=='#'){
                res-=1;
            }else{
                while(i<preorder.size()&&preorder[i]!=','){
                    i++;
                }
                res++;
            }
        }
        return res==0;
    }
     bool isValidSerialization1(string preorder) {
        stack<int> s;
        s.push(1);
        for(int i=0;i<preorder.size();i++){
            if(s.empty())return false;
            if(preorder[i]==',')continue;
            else if(preorder[i]=='#'){
                s.top()-=1;
                if(s.top()==0)s.pop();
            }else{
                while(i<preorder.size()&&preorder[i]!=','){
                    i++;
                }
                s.top()-=1;
                if(s.top()==0)s.pop();
                s.push(2);
            }
        }
        return s.empty();
    }
};

int main(){
    Solution s;
    string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    bool res = s.isValidSerialization(preorder);
    cout<<res<<endl;
}