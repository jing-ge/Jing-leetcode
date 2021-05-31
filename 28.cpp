// 28. Implement strStr()
// Implement strStr().

// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Clarification:

// What should we return when needle is an empty string? This is a great question to ask during an interview.

// For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

 

// Example 1:

// Input: haystack = "hello", needle = "ll"
// Output: 2
// Example 2:

// Input: haystack = "aaaaa", needle = "bba"
// Output: -1
// Example 3:

// Input: haystack = "", needle = ""
// Output: 0
 

// Constraints:

// 0 <= haystack.length, needle.length <= 5 * 104
// haystack and needle consist of only lower-case English characters.
// 通过次数339,204提交次数848,462

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0)return 0;
        if(haystack.size()==0||haystack.size()<needle.size()) return -1;
        for(int i=0;i<haystack.size();i++){
            if(haystack[i]==needle[0]){
                bool flag = true;
                for(int j=0;j<needle.size();j++){
                    if(haystack[j+i]!=needle[j]){
                        flag = false;
                        break;
                    }
                }
                if(flag)return i;
            }
        }
        return -1;
    }
    int strStr2(string haystack, string needle) {
        return haystack.find(needle);
    }
};

int main(){
    Solution s;
    string haystack = "", needle = "";
    int res = s.strStr2(haystack,needle);
    cout<<res<<endl;
    return 0;
}