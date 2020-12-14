// 49. Group Anagrams
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

//  

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// Example 2:

// Input: strs = [""]
// Output: [[""]]
// Example 3:

// Input: strs = ["a"]
// Output: [["a"]]


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<string,vector<string>> m;
        for(string str:strs){
            string s = str;
            sort(s.begin(),s.end());
            m[s].emplace_back(str);
        }

        for(auto t:m){
            res.emplace_back(t.second);
        }
        return res;
    }
};

int main(){
    Solution s = Solution();
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"}; 
    vector<vector<string>> res = s.groupAnagrams(strs);
    for(auto s :res){
        for(string ss:s){
            cout<<ss<<",";
        }
        cout<<endl;
    }
    return 0;
}