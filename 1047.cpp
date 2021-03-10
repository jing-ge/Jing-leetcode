// 1047. Remove All Adjacent Duplicates In String
// Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.

// We repeatedly make duplicate removals on S until we no longer can.

// Return the final string after all such duplicate removals have been made.  It is guaranteed the answer is unique.

 

// Example 1:

// Input: "abbaca"
// Output: "ca"
// Explanation: 
// For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
 

// Note:

// 1 <= S.length <= 20000
// S consists only of English lowercase letters.
// 通过次数41,116提交次数58,048

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    //string 也可以模拟栈
    string removeDuplicates1(string S) {
        stack<char> st;
        for(char c:S){
            if(st.empty()||st.top()!=c){
                st.push(c);
            }else{
                st.pop();
            }
        }
        string res;
        while(!st.empty()){
            res = st.top()+res;
            st.pop();
        }
        return res;
    }
    string removeDuplicates(string S){
        string st;
        for(char c:S){
            if(st.empty()||st.back()!=c){
                st.push_back(c);
            }else{
                st.pop_back();
            }
        }
        return st;
    }
};

int main(){
    Solution s;
    string S = "abbaca";
    string res = s.removeDuplicates(S);
    cout<<res<<endl;
    return 0;
}