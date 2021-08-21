// 541. Reverse String II
// Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

// If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.

 

// Example 1:

// Input: s = "abcdefg", k = 2
// Output: "bacdfeg"
// Example 2:

// Input: s = "abcd", k = 2
// Output: "bacd"
 

// Constraints:

// 1 <= s.length <= 104
// s consists of only lowercase English letters.
// 1 <= k <= 104
// 通过次数66,841提交次数109,953

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string reverseStr_(string s, int k) {
        vector<string> arr;
        string tmp;
        for(char c:s){
            tmp.push_back(c);
            if(tmp.size()==2*k){
                arr.push_back(tmp);
                tmp.clear();
            }
        }
        arr.push_back(tmp);
        for(auto &t:arr){
            int l = 0,r;
            if(t.size()<k){
                r = t.size()-1;
            }else{
                r = k-1;
            }
            while (l<r)
            {
                swap(t[l],t[r]);
                l++;
                r--;
            }
        }
        string res;
        for(auto t:arr){
            res+=t;
        }
        return res;
    }
    string reverseStr(string s, int k) {
        int n = s.size();
        for(int i=0;i<n;i+=2*k){
            reverse(s.begin()+i,s.begin()+min(i+k,n));
        }
        return s;
    }
};

int main(){
    Solution s;
    string str = "abcd";
    int k = 2;
    string res = s.reverseStr(str,k);
    cout<<res<<endl;
    return 0;
}