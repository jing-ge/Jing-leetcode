// 567. Permutation in String
// Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

// Example 1:

// Input: s1 = "ab" s2 = "eidbaooo"
// Output: True
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:

// Input:s1= "ab" s2 = "eidboaoo"
// Output: False
 

// Constraints:

// The input strings only contain lower case letters.
// The length of both given strings is in range [1, 10,000].
// 通过次数61,463提交次数154,024
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> cnt1,cnt2;
    bool checkInclusion(string s1, string s2) {
        cnt1 = vector<int>(26,0);
        cnt2 = vector<int>(26,0);
        int l1 = s1.size(),l2 = s2.size();
        if(l1>l2)return false;
        for(int i=0;i<l1;i++){
            cnt1[s1[i]-'a']++;
            cnt2[s2[i]-'a']++;
        }
        if(check())return true;
        for(int i=l1;i<l2;i++){
            cnt2[s2[i]-'a']++;
            cnt2[s2[i-l1]-'a']--;
            if(check())return true;
        }
        return false;
    }
    bool check(){
        for(int i=0;i<26;i++){
            if(cnt1[i]!=cnt2[i])return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    string s1 = "ab",s2 = "eidboaoo";
    cout<<s.checkInclusion(s1,s2)<<endl;;
    return 0;
}