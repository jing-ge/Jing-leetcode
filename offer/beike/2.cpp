#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @param k int整型 
     * @return string字符串
     */
    string NS_String(string s, int k) {
        // write code here
        map<char,vector<int>> m;
        unordered_set<int> set;
        for(int i=0;i<s.size();i++){
            m[s[i]].push_back(i);
        }
        int K = 0;
        if(k>=m.size())return "";
        for(auto t:m){
            if(K>=k)break;
            for(int i:t.second){
                set.insert(i);
            }
            K++;
        }
        string res;
        for(int i=0;i<s.size();i++){
            if(set.count(i))continue;
            res.push_back(s[i]);
        }
        return res;
    }
};

int main(){
    string str = "ccbb";
    int k = 1;
    Solution s;
    string res = s.NS_String(str,k);
    cout<<res<<endl;
    return 0;
}