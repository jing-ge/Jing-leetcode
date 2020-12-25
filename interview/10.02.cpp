// 面试题 10.02. Group Anagrams LCCI
// Write a method to sort an array of strings so that all the anagrams are in the same group.

// Note: This problem is slightly different from the original one the book.

// Example:

// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// Notes:

// All inputs will be in lowercase.
// The order of your output does not matter.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

void print(vector<vector<string>>&strs){
    for(auto i:strs){
        for(string s:i){
            cout<<s<<",";
        }
        cout<<endl;
    }
}

class Solution {
public:
    vector<vector<string>> groupAnagrams2(vector<string>& strs) {
        vector<string> tmp;
        set<string> myset;
        for(string s :strs){
            sort(s.begin(),s.end());
            tmp.push_back(s);
            myset.insert(s);
        }
        vector<vector<string>>res ;
        for(auto it = myset.begin();it!=myset.end();it++){
            vector<string> t;
            for(int j=0;j<strs.size();j++){
                if((*it)==tmp[j]){
                    t.push_back(strs[j]);
                }
            }
            res.push_back(t);
        }
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<string,vector<string>> map;
        for(string s:strs){
            string t = s;
            sort(s.begin(),s.end());
            map[s].push_back(t);
        }
        for(auto t:map){
            res.push_back(t.second);
        }
        return res;
    }
};

int main(){
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s = Solution();
    vector<vector<string>>res = s.groupAnagrams(strs); 
    print(res);
    return 0;
}