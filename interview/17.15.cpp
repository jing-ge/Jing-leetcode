// 面试题 17.15. Longest Word LCCI
// Given a list of words, write a program to find the longest word made of other words in the list. If there are more than one answer, return the one that has smallest lexicographic order. If no answer, return an empty string.

// Example:

// Input:  ["cat","banana","dog","nana","walk","walker","dogwalker"]
// Output:  "dogwalker"
// Explanation:  "dogwalker" can be made of "dog" and "walker".
// Note:

// 0 <= len(words) <= 200
// 1 <= len(words[i]) <= 100

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> allwords(words.begin(),words.end());
        string ans ;
        for(string &s:words){
            auto tmp = allwords;
            tmp.erase(s);
            if(isCombinated(s,tmp)){
                if(s.size()>ans.size())ans = s;
                if(s.size()==ans.size())ans = min(ans,s);
            }
        }
        return ans;
    }
    bool isCombinated(string s, unordered_set<string> &tmp){
        if(s.size()==0)return true;
        for(int i=1;i<=s.size();i++){
            if(tmp.count(s.substr(0,i))&&isCombinated(s.substr(i),tmp))return true;
        }
        return false;

    }
};

int main(){
    vector<string> words = {"cat","banana","dog","nana","walk","walker","dogwalker"};
    Solution s = Solution();
    string res = s.longestWord(words);
    cout<<res<<endl;
    return 0;
}