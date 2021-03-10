// 224. Basic Calculator
// Given a string s representing an expression, implement a basic calculator to evaluate it.

 

// Example 1:

// Input: s = "1 + 1"
// Output: 2
// Example 2:

// Input: s = " 2-1 + 2 "
// Output: 3
// Example 3:

// Input: s = "(1+(4+5+2)-3)+(6+8)"
// Output: 23
 

// Constraints:

// 1 <= s.length <= 3 * 105
// s consists of digits, '+', '-', '(', ')', and ' '.
// s represents a valid expression.
// 通过次数29,974提交次数75,686

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> ops;
        ops.push(1);
        long res = 0;
        int op = 1;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ')continue;
            else if(s[i]=='+'){
                op = ops.top();
            }else if(s[i]=='-'){
                op = -ops.top();
            }else if(s[i]=='('){
                ops.push(op);
            }else if(s[i]==')'){
                ops.pop();
            }else{
                long t = 0;
                while(i<s.size()&&s[i]>='0'&&s[i]<='9'){
                    t = t*10 + s[i]-'0';
                    i++;
                }
                i--;
                res += op*t;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    string str = "(1+(4+5+2)-3)+(6+8)";
    int res = s.calculate(str);
    cout<<res<<endl;
    return 0;
}