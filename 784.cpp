// 784. Letter Case Permutation
// Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.

// Return a list of all possible strings we could create. You can return the output in any order.

 

// Example 1:

// Input: S = "a1b2"
// Output: ["a1b2","a1B2","A1b2","A1B2"]
// Example 2:

// Input: S = "3z4"
// Output: ["3z4","3Z4"]
// Example 3:

// Input: S = "12345"
// Output: ["12345"]
// Example 4:

// Input: S = "0"
// Output: ["0"]
 

// Constraints:

// S will be a string with length between 1 and 12.
// S will consist only of letters or digits.
// 通过次数30,413提交次数45,556

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> res;
    vector<int> status;
    vector<string> letterCasePermutation(string S) {
        vector<int> arr;
        for(int i=0;i<S.size();i++){
            char c=S[i];
            if(c>='a'&&c<='z'||c>='A'&&c<='Z')arr.push_back(i);
        }
        res.push_back(S);
        backtrack(arr,0,S);
        return res;
    }
    char change(char c){
        if(c>='a'&&c<='z')return c-'a'+'A';
        else if(c>='A'&&c<='Z')return c-'A'+'a';
        else return c;
    }
    void backtrack(vector<int> &arr,int idx,string S){
        for(int i=idx;i<arr.size();i++){
            S[arr[i]] = change(S[arr[i]]);

            backtrack(arr,i+1,S);
            res.push_back(S);

            S[arr[i]] = change(S[arr[i]]);
        }
    }
};

int main(){
    Solution s;
    string S = "a1b2";
    vector<string> res = s.letterCasePermutation(S);
    for(auto t:res)cout<<t<<endl;
    return 0;
}