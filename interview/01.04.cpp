// 面试题 01.04. Palindrome Permutation LCCI
// Given a string, write a function to check if it is a permutation of a palin­ drome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.

//  

// Example1:

// Input: "tactcoa"
// Output: true（permutations: "tacocat"、"atcocta", etc.）


#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char,int> m;
        for(char c:s){
            m[c]++;
        }
        int cnt = 0;
        for(auto iter = m.begin();iter!=m.end();iter++){
            if(iter->second%2!=0)cnt++;
            if(cnt>1)return false;
        }
        return true;
    }
};

int main(){
    Solution s = Solution();
    string str = "tactcoa";
    bool res = s.canPermutePalindrome(str);
    cout<<res<<endl;
    return 0;
}