// 面试题 01.01. Is Unique LCCI
// Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?

// Example 1:

// Input: s = "leetcode"
// Output: false
// Example 2:

// Input: s = "abc"
// Output: true
//  

// Note:

// 0 <= len(s) <= 100


#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isUnique(string astr) {
        int map[26] = {0};
        for(char c:astr){
            if(map[c-'a']==1)return false;
            map[c-'a']++;
        }
        return true;
    }
};

int main(){
    string str = "leetcode";
    Solution s = Solution();
    bool res = s.isUnique(str);
    cout<<res<<endl;
    return 0;
}