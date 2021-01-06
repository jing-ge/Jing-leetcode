// 面试题 16.18. Pattern Matching LCCI
// You are given two strings, pattern and value. The pattern string consists of just the letters a and b, describing a pattern within a string. For example, the string catcatgocatgo matches the pattern aabab (where cat is a and go is b). It also matches patterns like a, ab, and b. Write a method to determine if value matches pattern. a and b cannot be the same string.

// Example 1:

// Input:  pattern = "abba", value = "dogcatcatdog"
// Output:  true
// Example 2:

// Input:  pattern = "abba", value = "dogcatcatfish"
// Output:  false
// Example 3:

// Input:  pattern = "aaaa", value = "dogcatcatdog"
// Output:  false
// Example 4:

// Input:  pattern = "abba", value = "dogdogdogdog"
// Output:  true
// Explanation:  "a"="dogdog",b=""，vice versa.
// Note:

// 0 <= len(pattern) <= 1000
// 0 <= len(value) <= 1000
// pattern only contains "a" and "b", value only contains lowercase letters.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool patternMatching(string pattern, string value) {
        int plen = pattern.size(),vlen = value.size();
        if(plen==0&&vlen==0)return true;
        if(plen==0)return false;

        int ac = 0,bc = 0;
        for(char &c:pattern){
            if(c=='a')ac++;
            else bc++;
        }

        int la = 0, lb = 0;
        if(ac!=0)la = vlen/ac;
        if(bc!=0)lb = vlen/bc;

        for(int i=0;i<=la;i++){
            for(int j=0;j<=lb;j++){
                if(i*ac+j*bc==vlen){
                    string sa = "#";
                    string sb = "#";

                    int index = 0;
                    for(int k=0;k<plen;++k){
                        if(pattern[k]=='a'){
                            if(sa=="#")sa = value.substr(index,i);
                            else {
                                if(sa!=value.substr(index,i))break;
                            }
                            index+=i;
                        }else{
                            if(sb=="#")sb = value.substr(index,j);
                            else {
                                if(sb!=value.substr(index,j))break;
                            }
                            index+=j;
                        }
                    }
                    if(index==vlen&&sa!=sb)return true;
                }

            }
        }
        return false;
    }
};

int main(){
    string pattern = "abba", value = "dogcatcatdog";
    Solution s = Solution();
    bool res = s.patternMatching(pattern, value);
    cout<<res<<endl;
    return 0;
}