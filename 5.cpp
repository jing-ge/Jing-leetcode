// 5. Longest Palindromic Substring
// Given a string s, return the longest palindromic substring in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"
// Example 3:

// Input: s = "a"
// Output: "a"
// Example 4:

// Input: s = "ac"
// Output: "a"
 

// Constraints:

// 1 <= s.length <= 1000
// s consist of only digits and English letters (lower-case and/or upper-case),
// 通过次数473,184提交次数1,434,461

#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int len = s.size();
        int maxi=0;
        int maxj=0;
        int maxlen=1;
        bool** dp = new bool* [len];
        for(int i=0;i<len;i++){
            dp[i] = new bool [len];
        }
        //初始化
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                dp[i][j]=false;
            }
        }
        //一维,二维回文初始化
        for(int i=0;i<len;i++){
            dp[i][i]=true;
        }
        for(int i=0;i<len-1;i++){
            if(s[i]==s[i+1]){
                maxi=i;
                maxj=i+1;
                maxlen=2;
                dp[i][i+1]=true;
            }
            
        }
        //dp
        for(int k=2;k<len;k++){
            int i=0;
            int j =i+k; 
            for(;i<len&&j<len;i++,j++){
                if(dp[i+1][j-1]&&(s[i]==s[j])){
                    if((j-i+1)>maxlen){
                        maxlen=j-i+1;
                        maxi=i;
                        maxj=j;
                    }
                    dp[i][j]=true;
                }
            }
        }
        res = s.substr(maxi,maxlen);
        return res;
    }
};

int main(){
    string s = "babad";
    Solution sol ;
    string res = sol.longestPalindrome(s);
    cout<<res<<endl;
    return 0;
}