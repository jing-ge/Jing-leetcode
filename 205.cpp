// 205. Isomorphic Strings
// Given two strings s and t, determine if they are isomorphic.

// Two strings are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

// Example 1:

// Input: s = "egg", t = "add"
// Output: true
// Example 2:

// Input: s = "foo", t = "bar"
// Output: false
// Example 3:

// Input: s = "paper", t = "title"
// Output: true
// Note:
// You may assume both s and t have the same length.

#include<iostream>
#include<string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>s2t;
        unordered_map<char,char>t2s;
        for(int i=0;i<s.size();i++){
            char x = s[i],y = t[i];
            if((s2t.count(x)&&s2t[x]!=y)||(t2s.count(y)&&t2s[y]!=x))return false;
            s2t[x] = y;
            t2s[y] = x;
        }
        return true;
    }
    bool isIsomorphic2(string s, string t) {
        int s2t[128] = {0};
        int t2s[128] = {0};
        for(int i=0;i<s.size();i++){
            char x = s[i],y = t[i];
            if(!s2t[x])s2t[x] = i+1;
            if(!t2s[y])t2s[y] = i+1;
            if(s2t[x]!=t2s[y])return false;
        }
        return true;
    }
};

int main(){
    string s = "egg";
    string t = "add";
    Solution sol = Solution();
    bool res = sol.isIsomorphic2(s,t);
    cout<<res<<endl;
    return 0;
}