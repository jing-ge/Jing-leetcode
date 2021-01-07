// 有个内含单词的超大文本文件，给定任意两个单词，找出在这个文件中这两个单词的最短距离(相隔单词数)。如果寻找过程在这个文件中会重复多次，而每次寻找的单词不同，你能对此优化吗?

// 示例：

// 输入：words = ["I","am","a","student","from","a","university","in","a","city"], word1 = "a", word2 = "student"
// 输出：1
// 提示：

// words.length <= 100000
// 通过次数9,220提交次数13,439

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/find-closest-lcci
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        unordered_map<string,vector<int>>map;
        for(int i=0;i<words.size();i++){
            map[words[i]].push_back(i);
        }
        vector<int> idx1 = map[word1];
        vector<int> idx2 = map[word2];
        int i=0,j=0,res = words.size();
        while(i<idx1.size()&&j<idx2.size()){
            res = min(res,abs(idx1[i]-idx2[j]));
            idx1[i]>idx2[j]?j++:i++;
        }
        return res;
    }
};

int main(){
    Solution s = Solution();
    vector<string> words = {"I","am","a","student","from","a","university","in","a","city"};
    string word1 = "a", word2 = "student";
    int res = s.findClosest(words,word1,word2);
    cout<<res<<endl;
    return 0;
}