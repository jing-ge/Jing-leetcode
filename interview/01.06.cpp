// 面试题 01.06. Compress String LCCI
// Implement a method to perform basic string compression using the counts of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. If the "compressed" string would not become smaller than the original string, your method should return the original string. You can assume the string has only uppercase and lowercase letters (a - z).

// Example 1:

// Input: "aabcccccaaa"
// Output: "a2b1c5a3"
// Example 2:

// Input: "abbccd"
// Output: "abbccd"
// Explanation: 
// The compressed string is "a1b2c2d1", which is longer than the original string.


#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string compressString(string S) {
        stringstream ss;
        int cnt = 1;
        char tmp = S[0];
        int i = 1;
        while (i<S.size())
        {
            if(S[i]!=tmp){
                ss<<tmp;
                ss<<cnt;
                tmp = S[i];
                cnt = 1;
                i++;
                continue;
            }
            i++;
            cnt++;
        }
        ss<<tmp;
        ss<<cnt;
        return ss.str().size()<S.size()?ss.str():S;
    }
};

int main(){
    Solution s = Solution();
    string str = "abbccd";
    string res = s.compressString(str);
    cout<<res<<endl;
    return 0;
}