// 721. Accounts Merge
// Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

// Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some email that is common to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

// After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

// Example 1:
// Input: 
// accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
// Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
// Explanation: 
// The first and third John's are the same person as they have the common email "johnsmith@mail.com".
// The second John and Mary are different people as none of their email addresses are used by other accounts.
// We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
// ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
// Note:

// The length of accounts will be in the range [1, 1000].
// The length of accounts[i] will be in the range [1, 10].
// The length of accounts[i][j] will be in the range [1, 30].
// 通过次数9,898提交次数24,283

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

void print(vector<string> res){
    for(auto t:res)cout<<t<<",";
    cout<<endl;
}

class UnionFind{
public:
    unordered_map<string,string> e2n;
    unordered_map<string,string> ids;
    UnionFind(vector<vector<string>>& accounts){
        for(auto t:accounts){
            for(int i=1;i<t.size();i++){
                e2n[t[i]] = t[0]; 
                ids[t[i]] = t[i];
            }
        }
        for(auto t:accounts){
            for(int i=2;i<t.size();i++){
                merge(t[i],t[i-1]);
            }
        }
        
    }
    string root(string &t){
        while(ids[t]!=t){
            t = ids[t];
        }
        return t;
    }
    void merge(string &a,string &b){
        // cout<<"merge:"<<a<<","<<b<<endl;
        string i = root(a);
        string j = root(b);
        if(i!=j){
            if(i<j)
                ids[j] = i;
            else
                ids[i] = j;
        }
        // for(auto t:ids){
        //     cout<<t.first<<",";
        // }
        // cout<<endl;
        // for(auto t:ids){
        //     cout<<t.second<<",";
        // }
        // cout<<endl;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        UnionFind uf = UnionFind(accounts);
        vector<vector<string>> res;
        unordered_map<string,vector<string>> tmp;
        for(auto &t:uf.ids){
            tmp[uf.root(t.second)].push_back(t.first);
        }
        // for(auto t:tmp){
        //     cout<<t.first<<":";print(t.second);
        // }
        for(auto &t:tmp){
            vector<string> vecs;
            vecs.push_back(uf.e2n[t.first]);
            sort(t.second.begin(),t.second.end());
            for(auto &s:t.second){
                vecs.push_back(s);
            }
            res.push_back(vecs);
        }
        return res;
    }
};

int main(){
    vector<vector<string>> accounts = {{"David","David0@m.co","David4@m.co","David3@m.co"},{"David","David5@m.co","David5@m.co","David0@m.co"},{"David","David1@m.co","David4@m.co","David0@m.co"},{"David","David0@m.co","David1@m.co","David3@m.co"},{"David","David4@m.co","David1@m.co","David3@m.co"}};
    Solution s = Solution();
    vector<vector<string>> res = s.accountsMerge(accounts);
    for(auto t:res){
        print(t);
    }
    return 0;
}