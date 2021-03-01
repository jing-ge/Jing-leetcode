// 395. Longest Substring with At Least K Repeating Characters
// Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.

 

// Example 1:

// Input: s = "aaabb", k = 3
// Output: 3
// Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
// Example 2:

// Input: s = "ababbc", k = 2
// Output: 5
// Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
 

// Constraints:

// 1 <= s.length <= 104
// s consists of only lowercase English letters.
// 1 <= k <= 105
// 通过次数32,766提交次数65,206

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
     int longestSubstring1(string s, int k) {
        int ret = 0;
        int n = s.length();
        for (int t = 1; t <= 26; t++) {
            int l = 0, r = 0;
            vector<int> cnt(26, 0);
            int tot = 0;
            int less = 0;
            while (r < n) {
                cnt[s[r] - 'a']++;
                if (cnt[s[r] - 'a'] == 1) {
                    tot++;
                    less++;
                }
                if (cnt[s[r] - 'a'] == k) {
                    less--;
                }

                while (tot > t) {
                    cnt[s[l] - 'a']--;
                    if (cnt[s[l] - 'a'] == k - 1) {
                        less++;
                    }
                    if (cnt[s[l] - 'a'] == 0) {
                        tot--;
                        less--;
                    }
                    l++;
                }
                if (less == 0) {
                    ret = max(ret, r - l + 1);
                }
                r++;
            }
        }
        return ret;
    }
    int longestSubstring2(string s, int k) {
        unordered_map<char,int> m;
        for(char &c:s){
            m[c]++;
        }
        vector<int> splits;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(m[s[i]]<k){
                splits.push_back(i);
            }
        }
        if(splits.size()<=0)return s.size();
        int res = 0;
        int left = 0;
        for(int i=0;i<splits.size();i++){
            int len = splits[i]-left;
            if(len>=k&&len>res){
                res = max(res,longestSubstring(s.substr(left,len),k));
            }
            left = splits[i]+1;
        }
        if(left<n-1){
            res = max(res,longestSubstring(s.substr(left,n-left),k));
        }
        return res;
    }
    //思路错误
    int longestSubstring(string s, int k) {
        unordered_map<char,int> map;
        int l = 0,r = 0;
        int res = 0;
        while(r<s.size()){
            map[s[r]]++;
            cout<<l<<","<<r<<endl;

            if(isk(map,k)){
                if(r<s.size()-1&&map[s[r+1]]>=k)r++;
                else{
                    res = max(r-l+1,res);
                    map[s[l]]--;
                    l++;
                }
            }else{
                r++;
            }
        }
        if(isk(map,k))res = max(r-l+1,res);
        return res;
    }
    bool isk(unordered_map<char,int> &map,int k){
        for(auto &t:map){
            cout<<t.first<<":"<<t.second<<endl;
        }
        for(auto &t:map){
            if(t.second<k)return false;
        }
        return true;
    }
};
int main(){
    Solution sol;
    string s = "aaabbb";
    int k = 3;
    int res = sol.longestSubstring(s,k);
    cout<<res<<endl;
    return 0;
}