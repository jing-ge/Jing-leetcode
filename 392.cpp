// 392. Is Subsequence
// Given a string s and a string t, check if s is subsequence of t.

// A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

// Follow up:
// If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

// Credits:
// Special thanks to @pbrother for adding this problem and creating all test cases.

//  

// Example 1:

// Input: s = "abc", t = "ahbgdc"
// Output: true
// Example 2:

// Input: s = "axc", t = "ahbgdc"
// Output: false
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0,j = 0;
        while(i<s.size()&&j<t.size()){
            if(s[i]==t[j]){
                i++;
            }
            j++;
        }
        return i==s.size();
    }

    bool isSubsequence_binary(string s, string t) {
        unordered_map<char,set<int>> mmap;
        for(int i=0;i<t.size();i++){
            mmap[t[i]].insert(i);
        }

        int pre = -1;
        for(auto & ch:s) {
            auto pos = mmap[ch];
            auto it = pos.upper_bound(pre);
            if(it == pos.end())
            return false;
            pre = *it;
        }
        return true;
    }
};

int main()
{
    Solution s = Solution();
    string s1 = "abc";
    string t1 = "ahbgdc";
    string s2 = "axc";
    string t2 = "ahbgdc";
    bool output1 = s.isSubsequence(s1,t1);
    bool output2 = s.isSubsequence(s2,t2);

    cout<< output1<<endl;
    cout<< output2<<endl;

}