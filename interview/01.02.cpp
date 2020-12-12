// 面试题 01.02. Check Permutation LCCI
// Given two strings,write a method to decide if one is a permutation of the other.

// Example 1:

// Input: s1 = "abc", s2 = "bca"
// Output: true
// Example 2:

// Input: s1 = "abc", s2 = "bad"
// Output: false


#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        int b1[26] = {0};
        int b2[26] = {0};
        if(s1.size()!=s2.size())return false;
        for(int i=0;i<s1.size();i++){
            b1[s1[i]-'a']++;
            b2[s2[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(b1[i]!=b2[i])return false;
        }
        return true;
    }
};

int main(){
    string s1 = "abc",s2 = "bad";
    Solution s = Solution();
    bool res = s.CheckPermutation(s1,s2);
    cout<<res<<endl;
    return 0;
}