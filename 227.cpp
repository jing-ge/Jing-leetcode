// 227. Basic Calculator II
// Given a string s which represents an expression, evaluate this expression and return its value. 

// The integer division should truncate toward zero.

 

// Example 1:

// Input: s = "3+2*2"
// Output: 7
// Example 2:

// Input: s = " 3/2 "
// Output: 1
// Example 3:

// Input: s = " 3+5 / 2 "
// Output: 5
 

// Constraints:

// 1 <= s.length <= 3 * 105
// s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
// s represents a valid expression.
// All the integers in the expression are non-negative integers in the range [0, 231 - 1].
// The answer is guaranteed to fit in a 32-bit integer.
// 通过次数37,845提交次数94,331

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        vector<int> st;
        int num = 0;
        char presign = '+';
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                num = num*10 + int(s[i]-'0');
            }
            if(!isdigit(s[i])&&s[i]!=' '||i==n-1){
                if(presign=='+'){
                    st.push_back(num);
                }else if(presign=='-'){
                    st.push_back(-num);
                }else if(presign=='*'){
                    st.back() *= num;
                }else if(presign=='/'){
                    st.back() /= num;
                }
                presign = s[i];
                num = 0;
            }
        }
        int res = 0;
        for(int i:st){
            res+=i;
            // cout<<i<<endl;
        }
        return res;
    }
};

int main(){
    Solution s;
    string str = "3+2*2";
    int res = s.calculate(str);
    cout<<res<<endl;
    return 0;
}