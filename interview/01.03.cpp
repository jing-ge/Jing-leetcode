// 面试题 01.03. String to URL LCCI
// Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end to hold the additional characters,and that you are given the "true" length of the string. (Note: If implementing in Java,please use a character array so that you can perform this operation in place.)

// Example 1:

// Input: "Mr John Smith ", 13
// Output: "Mr%20John%20Smith"
// Example 2:

// Input: "               ", 5
// Output: "%20%20%20%20%20"
//  

// Note:

// 0 <= S.length <= 500000

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string replaceSpaces(string S, int length) {
        string res;
        for(int i=0;i<length;i++){
            if(S[i]==' ')res+="%20";
            else res+=S[i];
        }
        return res;
    }
};


int main(){
    Solution s = Solution();
    string str= "Mr John Smith";
    int length = 13;
    string res = s.replaceSpaces2(str,length);
    return 0;
}