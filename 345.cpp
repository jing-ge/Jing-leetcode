// 345. Reverse Vowels of a String
// Given a string s, reverse only all the vowels in the string and return it.

// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both cases.

 

// Example 1:

// Input: s = "hello"
// Output: "holle"
// Example 2:

// Input: s = "leetcode"
// Output: "leotcede"
 

// Constraints:

// 1 <= s.length <= 3 * 105
// s consist of printable ASCII characters.
// 通过次数98,351提交次数184,412

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string reverseVowels_(string s) {
        unordered_set<char> us {'a','e','i','o','u','A','E','I','O','U'};
        int n = s.size();
        int l = 0,r = n-1;
        while (l<r)
        {
            while(l<n&&us.count(s[l])==0){
                l++;
            }
            while (r>0&&us.count(s[r])==0)
            {
                r--;
            }
            if(l<r){
                swap(s[l],s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
    void print(vector<int> d){
        for(int i:d)cout<<i<<",";
        cout<<endl;
    }
    string reverseVowels(string s) {
        unordered_set<char> us {'a','e','i','o','u','A','E','I','O','U'};
        vector<int> idx;
        for(int i=0;i<s.size();i++){
            if(us.count(s[i])>0)idx.push_back(i);
        }
        print(idx);
        int l = 0,r = idx.size()-1;
        while(l<r){
            swap(s[idx[l]],s[idx[r]]);
            l++;
            r--;
        }
        return s;
    }
};

int main(){
    string str = "hello";
    Solution s;
    string res = s.reverseVowels(str);
    cout<<res<<endl;
    return 0;
}