// 316. Remove Duplicate Letters
// Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

// Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

//  

// Example 1:

// Input: s = "bcabc"
// Output: "abc"
// Example 2:

// Input: s = "cbacdcbc"
// Output: "acdb"


#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> ustack;
        set<char> uset;
        map<char,int> umap;

        for(int i = 0; i< s.size();i++){
            umap[s[i]] = i;
        }

        for(int i = 0; i< s.size();i++){
            char c = s[i];
            if(uset.count(c)==0){
                while(!ustack.empty() && c<ustack.top() && umap[ustack.top()]>i){
                    uset.erase(ustack.top());
                    ustack.pop();
                }
                uset.insert(c);
                ustack.push(c);
            }
        }
        
        string res;
        while(ustack.size()>0){
            res = ustack.top()+res;
            ustack.pop();
        }
        return res;
    }
};


int main(){
    Solution s = Solution();
    string ss = "cbacdcbc";
    string res = s.removeDuplicateLetters(ss);
    cout<<res<<endl;
}