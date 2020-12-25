// 面试题 10.10. Rank from Stream LCCI
// Imagine you are reading in a stream of integers. Periodically, you wish to be able to look up the rank of a number x (the number of values less than or equal to x). lmplement the data structures and algorithms to support these operations. That is, implement the method track (int x), which is called when each number is generated, and the method getRankOfNumber(int x), which returns the number of values less than or equal to x.

// Note: This problem is slightly different from the original one in the book.

// Example:

// Input:
// ["StreamRank", "getRankOfNumber", "track", "getRankOfNumber"]
// [[], [1], [0], [0]]
// Output:
// [null,0,null,1]
// Note:

// x <= 50000
// The number of calls of both track and getRankOfNumber methods are less than or equal to 2000.
// 通过次数2,464提交次数3,968

#include <iostream>
#include <vector>

using namespace std;

class StreamRank1 {
public:
    vector<int>data;
    StreamRank1() {
    }
    
    void track(int x) {
        data.push_back(x);
    }
    
    int getRankOfNumber(int x) {
        int res = 0;
        for(int &i:data){
            if(i<=x)res++;
        }
        return res;
    }
};

class StreamRank2 {
public:
    struct TreeNode
    {
        int sum;
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x):val(x),sum(1),left(nullptr),right(nullptr){}
    };
    StreamRank2() {
        root = nullptr;
    }
    
    void track(int x) {
        if(root==nullptr){
            root = new TreeNode(x);
            return;
        }
        TreeNode* cur = root;
        while(cur){
            if(x<=cur->val){
                cur->sum++;
                if(cur->val==x)break;
                if(!cur->left){
                    cur->left = new TreeNode(x);
                    break;
                }
                cur = cur->left;
            }else{
                if(!cur->right){
                    cur->right = new TreeNode(x);
                    break;
                }
                cur = cur->right;
            }
        }
    }
    int getRankOfNumber(int x) {
        int res = 0;
        if(root!=nullptr){
            TreeNode *tmp = root;
            while(tmp&&tmp->val!=x){
                if(x<tmp->val)
                    tmp = tmp->left;
                else{
                    res+=tmp->sum;
                    tmp = tmp->right;
                }
            }
            if(tmp!=nullptr)res += tmp->sum;
        }
        return res;  
    }
    TreeNode* root;
};

int main(){
    StreamRank2 sr = StreamRank2();
    sr.getRankOfNumber(1);
    sr.track(0);
    sr.getRankOfNumber(0);
    return 0;
}