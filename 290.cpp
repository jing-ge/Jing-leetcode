// 290. Word Pattern
// Given a pattern and a string s, find if s follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

//  

// Example 1:

// Input: pattern = "abba", s = "dog cat cat dog"
// Output: true
// Example 2:

// Input: pattern = "abba", s = "dog cat cat fish"
// Output: false
// Example 3:

// Input: pattern = "aaaa", s = "dog cat cat dog"
// Output: false
// Example 4:

// Input: pattern = "abba", s = "dog dog dog dog"
// Output: false

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern2(string pattern, string s) {
        unordered_map<string,char> str2ch;
        unordered_map<char,string> ch2str;

        int m = s.size();
        int i = 0;
        for(char c:pattern){
            if(i>=m)return false;
            int j = i;
            while(j<m&&s[j]!=' ')j++;
            string word = s.substr(i,j-i);
            if(str2ch.count(word)&&str2ch[word]!=c)return false;
            if(ch2str.count(c)&&ch2str[c]!=word)return false;
            str2ch[word] = c;
            ch2str[c] = word;
            i =j+1;
        }
        return i>=m;
    }
    vector<string> res;
    vector<string>& str2vec(string &s){
        int i = 0;
        while(i<s.size()){
            int j = i;
            while(j<s.size()&&s[j]!=' ')j++;
            string word = s.substr(i,j-i);
            res.push_back(word);
            i = j+1;
        }
        return res;
    }

    bool wordPattern(string pattern, string s){
        str2vec(s);
        unordered_map<string,char> map;
        if(res.size()!=pattern.length())return false;
        for(int i=0;i<res.size();i++){
            if(map.count(res[i])&&map[res[i]]!=pattern[i])return false;
            map[res[i]] = pattern[i];
        }
        return true;
    }
};

int main(){
    string pattern = "abba";
    string str = "dog cat cat dog";
    Solution s = Solution();
    bool res = s.wordPattern(pattern,str);
    cout<<res<<endl;
    return 0;
}