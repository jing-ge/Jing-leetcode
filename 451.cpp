// 451. Sort Characters By Frequency
// Given a string s, sort it in decreasing order based on the frequency of characters, and return the sorted string.

 

// Example 1:

// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
// Example 2:

// Input: s = "cccaaa"
// Output: "aaaccc"
// Explanation: Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
// Note that "cacaca" is incorrect, as the same characters must be together.
// Example 3:

// Input: s = "Aabb"
// Output: "bbAa"
// Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.
 

// Constraints:

// 1 <= s.length <= 5 * 105
// s consists of English letters and digits.
// 通过次数65,419提交次数93,488

#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

struct cmp{
    bool operator() (pair<char,int> &a,pair<char,int> &b){
        return a.second==b.second?a.first<b.first:a.second<b.second;
    }
};

class Solution {
public:
    string frequencySort_sort(string s) {
        unordered_map<char,int> map;
        for(char& c:s){
            map[c]++;
        }
        vector<pair<char,int>> vec;
        for(auto t:map){
            vec.push_back(t);
        }
        sort(vec.begin(),vec.end(),[](const pair<char,int> &a, const pair<char,int> &b){
            return a.second > b.second;
        });
        string res;
        for(auto &t:vec){
            for(int i=0;i<t.second;i++){
                res.push_back(t.first);
            }
        }
        return res;
    }
    string frequencySort_buckets(string s) {
        int feq_max = 0;
        unordered_map<char,int> map;
        for(char& c:s){
            map[c]++;
            feq_max = max(feq_max,map[c]);
        }
        vector<string> arr(feq_max+1);
        for(auto &t:map){
            arr[t.second].push_back(t.first);
        }
        string res;
        for(int i=feq_max;i>0;i--){
            if(arr[i].size()==0)continue;
            for(char c:arr[i]){
                for(int j=0;j<map[c];j++){
                    res.push_back(c);
                }
            }
        }
        return res;
    }
    string frequencySort(string s) {
        unordered_map<char,int> map;
        for(char& c:s){
            map[c]++;
        }
        priority_queue<pair<char,int>, vector<pair<char,int>>, cmp> pq;
        for(auto t:map){
            pq.push(t);
        }
        string res;
        while (!pq.empty())
        {
            auto t = pq.top();
            pq.pop();
            for(int i=0;i<t.second;i++){
                res.push_back(t.first);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    string str = "tree";
    string res = s.frequencySort(str);
    cout<<res<<endl;
    return 0;
}