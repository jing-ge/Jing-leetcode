// 面试题 17.25. Word Rectangle LCCI
// Given a list of millions of words, design an algorithm to create the largest possible rectangle of letters such that every row forms a word (reading left to right) and every column forms a word (reading top to bottom). The words need not be chosen consecutively from the list but all rows must be the same length and all columns must be the same height.

// If there are more than one answer, return any one of them. A word can be used more than once.

// Example 1:

// Input: ["this", "real", "hard", "trh", "hea", "iar", "sld"]
// Output:
// [
//    "this",
//    "real",
//    "hard"
// ]
// Example 2:

// Input: ["aa"]
// Output: ["aa","aa"]
// Notes:

// words.length <= 1000
// words[i].length <= 100
// It's guaranteed that all the words are randomly generated.
// 通过次数823提交次数1,708

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Trie{
public:
    vector<Trie*> childs;
    bool isLeaf;
    Trie(){
        childs = vector<Trie*>(26,nullptr);
        isLeaf = false;
    }
};

class Solution {
public:
    Trie* root;
    unordered_map<int,unordered_set<string>> map;
    int maxArea = 0;
    int maxLen = 0;
    vector<string> res;
    vector<string> maxRectangle(vector<string>& words) {
        //构造字典树
        root = new Trie();
        for(string &s:words){
            Trie* node = root;
            for(char c:s){
                if(node->childs[c-'a']==nullptr){
                    node->childs[c-'a'] = new Trie();
                }
                node = node->childs[c-'a'];
            }
            node->isLeaf = true;
        }
        //构建字典
        for(string &s:words){
            maxLen = max((int)s.size(),maxLen);
            map[s.size()].insert(s);
        }
        vector<string> path;
        for(auto item:map){
            path.clear();
            dfs(item.second,path,item.first);
        }
        return res;
    }

    void dfs(unordered_set<string>& dic, vector<string>&path,int wordLen){
        if(wordLen*maxLen<=maxArea)return;

        if(path.size()>maxLen)return;

        for(auto it = dic.begin();it!=dic.end();it++){
            path.push_back(*it);
            vector<bool> tmp = isValid(path);
            if(tmp[0]){
                int area = path.size()*path[0].size();
                if(tmp[1]&&(area>maxArea)){
                    maxArea = area;
                    res = path;
                }
                dfs(dic,path,wordLen);
            }
            path.pop_back();
        }
    }

    vector<bool> isValid(vector<string>&path){
        bool allLeaf = true;
        int m = path.size();
        int n = path[0].size();
        for(int j=0;j<n;j++){
            Trie* node = root;
            for(int i=0;i<m;i++){
                int c = path[i][j]-'a';
                if(node->childs[c]==nullptr)return {false,false};
                node = node->childs[c];
            }
            if(!node->isLeaf)allLeaf = false;
        }
        return {true,allLeaf};
    }
};

int main(){
    Solution s = Solution();
    vector<string> words = {"aa"};
    vector<string> res = s.maxRectangle(words);
    for(string s:res){
        cout<<s<<endl;
    }
    return 0;
}