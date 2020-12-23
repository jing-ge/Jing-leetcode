// 面试题 08.07. Permutation I LCCIWrite a method to compute all permutations of a string of unique characters.

// Example1:

//  Input: S = "qwe"
//  Output: ["qwe", "qew", "wqe", "weq", "ewq", "eqw"]
// Example2:

//  Input: S = "ab"
//  Output: ["ab", "ba"]
// Note:

// All charaters are English letters.
// 1 <= S.length <= 9
// 通过次数13,144提交次数16,198


#include <iostream>
#include <vector>

using namespace std;

void print(vector<string>&res){
    for(string s :res){
        cout<<s<<endl;
    }
}

class Solution {
public:
    set<string>res;
    vector<string> permutation(string S) {
        dfs(S,0);
        return vector<string>(res.begin(),res.end());
    }
    void dfs(string S,int k){
        if(k==S.size()&&!res.count(S)){
            res.insert(S);
            return;
        }
        for(int j=k;j<S.size();j++){
            swap(S[j],S[k]);
            dfs(S,k+1);
        }
    }
};

int main(){
    string str = "qwe";
    Solution s = Solution();
    vector<string> res= s.permutation(str);
    print(res);
    return 0;
}