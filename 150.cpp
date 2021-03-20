// 150. Evaluate Reverse Polish Notation
// Evaluate the value of an arithmetic expression in Reverse Polish Notation.

// Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

// Note that division between two integers should truncate toward zero.

// It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.

 

// Example 1:

// Input: tokens = ["2","1","+","3","*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9
// Example 2:

// Input: tokens = ["4","13","5","/","+"]
// Output: 6
// Explanation: (4 + (13 / 5)) = 6
// Example 3:

// Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
// Output: 22
// Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
// = ((10 * (6 / (12 * -11))) + 17) + 5
// = ((10 * (6 / -132)) + 17) + 5
// = ((10 * 0) + 17) + 5
// = (0 + 17) + 5
// = 17 + 5
// = 22
 

// Constraints:

// 1 <= tokens.length <= 104
// tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int a,b,t;
        for(string &s:tokens){
            if(s=="+"){
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                t = a+b;
                st.push(t);
            }else if(s=="-"){
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                t = b-a;
                st.push(t);
            }else if(s=="*"){
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                t = a*b;
                st.push(t);             
            }else if(s=="/"){
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                t = b/a;
                st.push(t);
            }else{
                int t = stoi(s);
                st.push(t);
            }
        }
        return st.top();
    }
};

int main(){
    Solution s;
    vector<string> tokens= {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int res = s.evalRPN(tokens);
    cout<<res<<endl;
    return 0;
}
