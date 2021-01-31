// 839. Similar String Groups
// Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y. Also two strings X and Y are similar if they are equal.

// For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

// Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

// We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?

 

// Example 1:

// Input: strs = ["tars","rats","arts","star"]
// Output: 2
// Example 2:

// Input: strs = ["omv","ovm"]
// Output: 1
 

// Constraints:

// 1 <= strs.length <= 100
// 1 <= strs[i].length <= 1000
// sum(strs[i].length) <= 2 * 104
// strs[i] consists of lowercase letters only.
// All words in strs have the same length and are anagrams of each other.
// 通过次数5,493提交次数12,564

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class UnionFind{
public:
    vector<int> parent;
    vector<int> size;
    int n;
    UnionFind(int _n){
        n = _n;
        for(int i=0;i<n;i++){
            parent.push_back(i);
            size.push_back(1);
        }
    }
    int root(int i){
        while(parent[i]!=i){
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;
    }
    int merge(int i,int j){
        i = root(i);
        j = root(j);
        if(i==j)return false;
        if(size[i]<size[j]){
            parent[i] = j;
            size[j] += size[i];
        }else{
            parent[j] = i;
            size[i] += size[j];
        }
        n--;
        return true;
    }
};

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        UnionFind uf(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(uf.root(i)==uf.root(j))continue;
                else if(check(strs[i],strs[j])){
                    uf.merge(i,j);
                }
            }
        }
        return uf.n;
    }
    bool check(const string &a, const string &b) {
        if(a.size()!=b.size())return false;
        int len = a.size();
        int num = 0;
        for (int i = 0; i < len; i++) {
            if (a[i] != b[i]) {
                num++;
                if (num > 2) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
    vector<string> strs = {"tars","rats","arts","star"};
    Solution s;
    int res = s.numSimilarGroups(strs);
    cout<<res<<endl;
    return 0;
}