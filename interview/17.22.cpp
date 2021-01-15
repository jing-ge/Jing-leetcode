// 面试题 17.22. Word Transformer LCCI
// Given two words of equal length that are in a dictionary, write a method to transform one word into another word by changing only one letter at a time. The new word you get in each step must be in the dictionary.

// Write code to return a possible transforming sequence. If there are more that one sequence, any one is ok.

// Example 1:

// Input:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]

// Output:
// ["hit","hot","dot","lot","log","cog"]
// Example 2:

// Input:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]

// Output: []

// Explanation: endWord "cog" is not in the dictionary, so there's no possible transforming sequence.
// 通过次数5,213提交次数14,940

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;


class UF{
public:
    vector<int> ids;
    vector<int> sizes;
    UF(int n){
        for(int i=0;i<n;i++){
            ids.push_back(i);
            sizes.push_back(1);
        }
    }
    int root(int t){
        while(t!=ids[t])t = ids[t];
        return t;
    }
    vector<int> father(int i){
        vector<int>res ;
        res.push_back(i);
        while(i!=ids[i]){
            i = ids[i];
            res.push_back(i);
        }
        return res;
    }
    
    void unions(int i,int j){
        int p = root(i);
        int q = root(j);
        if(sizes[p]<sizes[q]){
            ids[p] = q;
            sizes[q]+=sizes[p];
        }else{
            ids[q] = p;
            sizes[p] += sizes[q];
        }
    }
};



void print(vector<int> &res){
    for(int &i:res)cout<<i<<",";
    cout<<endl;
}

class Solution {
public:
    bool isTrans(string& a, string &b){
        if(a.size()!=b.size())return false;
        int cnt=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i])cnt++;
        }
        return cnt==1;
    }
    unordered_map<string,int> map;
    vector<bool> visited;
    vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        for(int i=0;i<wordList.size();i++)map[wordList[i]]=i;
        if(map.count(endWord)==0)return {};
        if(map.count(beginWord)==0){
            wordList.push_back(beginWord);
            map[beginWord] = n;
        }
        n = wordList.size();
        if(map.count(endWord)==0)return {};
        vector<vector<int>> graph(n,vector<int>());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isTrans(wordList[i], wordList[j])){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        // print(graph,wordList);
        vector<string> res = {beginWord};
        visited = vector<bool>(wordList.size(),false);
        visited[map[beginWord]] = true;

        if(dfs(map[beginWord],map[endWord],graph,res,wordList))return res;
        else return {};
    }

    bool dfs(int start,int end,vector<vector<int>>&graph, vector<string>&res,vector<string>& wordList){
        if(start==end)return true;
        for(int &i:graph[start]){
            if(visited[i]==false){
                res.push_back(wordList[i]);
                visited[i]=true;
                if(dfs(i,end,graph,res,wordList))return true;
                res.pop_back();
                // visited[i] = false;
            }
        }
        return false;
    }
};

int main(){
    string beginWord = "qa",endWord = "sq";
    vector<string> wordList = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
    Solution s = Solution();
    vector<string> res = s.findLadders(beginWord, endWord, wordList);
    for(auto t:res){
        cout<<t<<"->";
    }
    cout<<endl;
    return 0;
}