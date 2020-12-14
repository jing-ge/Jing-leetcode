// 面试题 01.09. String Rotation LCCI
// Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 (e.g.,"waterbottle" is a rotation of"erbottlewat"). Can you use only one call to the method that checks if one word is a substring of another?

// Example 1:

// Input: s1 = "waterbottle", s2 = "erbottlewat"
// Output: True
// Example 2:

// Input: s1 = "aa", s2 = "aba"
// Output: False

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if(s1.size() != s2.size())return false;
        string s = s1+s1;
        return s.find(s2)!=string::npos;
    }

    bool isFlipedString(string s1, string s2) {
        return s1.size() == s2.size()&&(s1+s1).find(s2)!=-1;
    }
};

int main(){
    string s1 = "waterbottle"; 
    string s2 = "erbottlewat";

    Solution s = Solution();
    bool res = s.isFlipedString(s1, s2);
    cout<<res<<endl;
    return 0;
}