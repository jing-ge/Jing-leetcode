// 面试题 17.17. Multi Search LCCI
// Given a string band an array of smaller strings T, design a method to search b for each small string in T. Output positions of all strings in smalls that appear in big, where positions[i] is all positions of smalls[i].

// Example:

// Input: 
// big = "mississippi"
// smalls = ["is","ppi","hi","sis","i","ssippi"]
// Output:  [[1,4],[8],[],[3],[1,4,7,10],[5]]
// Note:

// 0 <= len(big) <= 1000
// 0 <= len(smalls[i]) <= 1000
// The total number of characters in smalls will not exceed 100000.
// No duplicated strings in smalls.
// All characters are lowercase letters.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        unordered_map<string,vector<int>> map;
        int maxlength = 0;
        for(string &s:smalls){
            map[s] = vector<int>();
            maxlength = max(maxlength,(int)s.size());
        }
        for(int i=0;i<big.length();i++){
            for(int j=1;j<=maxlength&&i+j<=big.size();j++){
                string tmp = big.substr(i,j);
                if(map.count(tmp)!=0){
                    map[tmp].push_back(i);
                }
            }
        }
        vector<vector<int>> res;
        for(string &s:smalls){
            res.push_back(map[s]);
        }
        return res;
    }
};

int main(){
    Solution s = Solution();
    string big = "mississippi";
    vector<string> smalls = {"is","ppi","hi","sis","i","ssippi"};
    vector<vector<int>>res = s.multiSearch(big,smalls);
    for(auto t:res){
        for(int i:t){
            cout<<i<<',';
        }
        cout<<endl;
    }
    return 0;
}
