// 面试题 17.26. Sparse Similarity LCCI
// The similarity of two documents (each with distinct words) is defined to be the size of the intersection divided by the size of the union. For example, if the documents consist of integers, the similarity of {1, 5, 3} and {1, 7, 2, 3} is 0.4, because the intersection has size 2 and the union has size 5. We have a long list of documents (with distinct values and each with an associated ID) where the similarity is believed to be "sparse". That is, any two arbitrarily selected documents are very likely to have similarity 0. Design an algorithm that returns a list of pairs of document IDs and the associated similarity.

// Input is a 2D array docs, where docs[i] is the document with id i. Return an array of strings, where each string represents a pair of documents with similarity greater than 0. The string should be formatted as  {id1},{id2}: {similarity}, where id1 is the smaller id in the two documents, and similarity is the similarity rounded to four decimal places. You can return the array in any order.

// Example:

// Input: 
// [
//   [14, 15, 100, 9, 3],
//   [32, 1, 9, 3, 5],
//   [15, 29, 2, 6, 8, 7],
//   [7, 10]
// ]
// Output:
// [
//   "0,1: 0.2500",
//   "0,2: 0.1000",
//   "2,3: 0.1429"
// ]
// Note:

// docs.length <= 500
// docs[i].length <= 500
// The number of document pairs with similarity greater than 0 will not exceed 1000.

#include <vector>
#include <iostream>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

void print(set<int> &s){
    for(auto it = s.begin();it!=s.end();it++){
        cout<<*it<<",";
    }
    cout<<endl;
}

class Solution {
public:
    //超时 O(n2D)
    vector<string> computeSimilarities1(vector<vector<int>>& docs) {
        int n = docs.size();
        vector<string> res;
        set<int> a,b,c,d;
        char temp[256];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                a = set<int>(docs[i].begin(),docs[i].end());
                b = set<int>(docs[j].begin(),docs[j].end());
                set_intersection(a.begin(),a.end(),b.begin(),b.end(),insert_iterator<set<int>>(c, c.begin()));
                if(c.size()==0) continue;

                double sim = (double)c.size()/(a.size()+b.size()-c.size());
                sprintf(temp,"%d,%d: %0.4lf",i,j,sim+1e-9);             
                res.push_back(temp);
                c.clear();
            }
        }
        return res;
    }
    vector<string> computeSimilarities(vector<vector<int>>& docs) {
        unordered_map<int,vector<int>> mp1;
        for(int i=0;i<docs.size();i++){
            for(int j:docs[i]){
                mp1[j].push_back(i);
            }
        }
        unordered_map<int, unordered_map<int, int>> mp2;
        for(auto &t:mp1){
            int n = t.second.size();
            for(int i=0;i+1<n;i++){
                for(int j=i+1;j<n;j++){
                    mp2[t.second[i]][t.second[j]]++;
                }
            }
        }
        vector<string>res;
        char temp[256];
        for(auto &item:mp2){
            int id1 = item.first;
            for(auto &item2:item.second){
                int id2 = item2.first;
                double sim = (double)item2.second/(docs[id1].size()+docs[id2].size()-item2.second);
                sprintf(temp,"%d,%d: %0.4lf",id1,id2,sim+1e-9);
                res.push_back(temp);
            }
        }
        return res;
    }
};

int main(){
    vector<vector<int>> docs = {
        {14, 15, 100, 9, 3},
        {32, 1, 9, 3, 5},
        {15, 29, 2, 6, 8, 7},
        {7, 10}
    };
    Solution s = Solution();
    vector<string>res = s.computeSimilarities(docs);
    for(string s:res){
        cout<<s<<endl;
    }
    return 0;
}