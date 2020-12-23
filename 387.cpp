// 387. First Unique Character in a StringGiven a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

// Examples:

// s = "leetcode"
// return 0.

// s = "loveleetcode"
// return 2.
//  

// Note: You may assume the string contains only lowercase English letters.


#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int map[26] = {0};
        for(char c:s){
            map[c-'a']++;
        }
        for(int i=0;i<s.length();i++){
            if(map[s[i]-'a']==1)return i;
        }
        return -1;
    }
};

int main(){
    string str = "leetcode";
    Solution s = Solution();
    int res = s.firstUniqChar(str);
    cout<<res<<endl;
    return 0;
}