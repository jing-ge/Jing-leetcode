// 389. Find the Difference
// You are given two strings s and t.

// String t is generated by random shuffling string s and then add one more letter at a random position.

// Return the letter that was added to t.

//  

// Example 1:

// Input: s = "abcd", t = "abcde"
// Output: "e"
// Explanation: 'e' is the letter that was added.
// Example 2:

// Input: s = "", t = "y"
// Output: "y"
// Example 3:

// Input: s = "a", t = "aa"
// Output: "a"
// Example 4:

// Input: s = "ae", t = "aea"
// Output: "a"


#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    char findTheDifference1(string s, string t) {
        int map1[26] = {0};
        int map2[26] = {0};
        for(char c:s){
            map1[c-'a']++;
        }
        for(char c:t){
            map2[c-'a']++;
        }
        for(int i=0;i<26;i++){
            if((map2[i]-map1[i]) == 1)return i+'a';
        }
        return 'a';
    }
    char findTheDifference2(string s, string t) {
        int cnts=0,cntt=0;
        for(char c:s){
            cnts+=c;
        }
        for(char c:t){
            cntt+=c;
        }
        return cntt-cnts;
    }
    char findTheDifference(string s, string t) {
        int ret=0;
        for(char c:s){
            ret ^= c;
        }
        for(char c:t){
            ret ^= c;
        }
        return ret;
    }
};

int main()
{
    Solution so = Solution();
    string s = "abcd",t  = "abcde";
    char res = so.findTheDifference2(s,t);
    cout<<res<<endl;
    return 0;
}