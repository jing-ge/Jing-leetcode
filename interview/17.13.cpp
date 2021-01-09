// 面试题 17.13. 恢复空格
// 哦，不！你不小心把一个长篇文章中的空格、标点都删掉了，并且大写也弄成了小写。像句子"I reset the computer. It still didn’t boot!"已经变成了"iresetthecomputeritstilldidntboot"。在处理标点符号和大小写之前，你得先把它断成词语。当然了，你有一本厚厚的词典dictionary，不过，有些词没在词典里。假设文章用sentence表示，设计一个算法，把文章断开，要求未识别的字符最少，返回未识别的字符数。

// 注意：本题相对原题稍作改动，只需返回未识别的字符数

 

// 示例：

// 输入：
// dictionary = ["looked","just","like","her","brother"]
// sentence = "jesslookedjustliketimherbrother"
// 输出： 7
// 解释： 断句后为"jess looked just like tim her brother"，共7个未识别字符。
// 提示：

// 0 <= len(sentence) <= 1000
// dictionary中总字符数不超过 150000。
// 你可以认为dictionary和sentence中只包含小写字母。
// 通过次数21,849提交次数39,305

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;


class TrieNode{
public:
    vector<TrieNode*> childs;
    bool isWord;
    TrieNode(){
        isWord = false;
        childs = vector<TrieNode*>(26,nullptr);
    }
};

class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        unordered_set<string> dic(dictionary.begin(),dictionary.end());
        int n = sentence.size();
        vector<int>dp(n+1,0);
        for(int i=1;i<=n;i++){
            dp[i] = dp[i-1]+1;
            for(int idx = 0;idx<i;idx++){
                if(dic.count(sentence.substr(idx,i-idx))){
                    dp[i] = min(dp[i],dp[idx]);
                }
            }
        }
        return dp[n];
    }
    //////////////////////////////////////////////////////////////////////////////////
    TrieNode* root;
    int respace2(vector<string>& dictionary, string sentence) {
        root = new TrieNode();
        makeTrie(dictionary);
        int n = sentence.size();
        vector<int>dp(n+1,0);
        for(int i = n-1;i>=0;i--){
            dp[i] = n-i;
            TrieNode* node = root;
            for(int j=i;j<n;j++){
                int c = sentence[j]-'a';
                if(node->childs[c]==nullptr){
                    dp[i] = min(dp[i],j-i+1+dp[j+1]);
                    break;
                }
                if(node->childs[c]->isWord){
                    dp[i] = min(dp[i],dp[j+1]);
                }else{
                    dp[i] = min(dp[i],j-i+1+dp[j+1]);
                }
                node = node->childs[c];
            }
        }
        return dp[0];
    }

    void makeTrie(vector<string>& dictionary){
        for(string s:dictionary){
            TrieNode* node = root;
            for(int k=0;k<s.size();k++){
                int i = s[k]-'a';
                if(node->childs[i]==nullptr){
                    node->childs[i] = new TrieNode();
                }
                node = node->childs[i];
            }
            node->isWord = true;
        }
    }
};


int main(){
    vector<string> dictionary = {"looked","just","like","her","brother"};
    string sentence = "jesslookedjustliketimherbrother";
    Solution s = Solution();
    int res = s.respace2(dictionary,sentence);
    cout<<res<<endl;
    return 0;
}