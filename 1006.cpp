// 1006. Clumsy Factorial
// Normally, the factorial of a positive integer n is the product of all positive integers less than or equal to n.  For example, factorial(10) = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1.

// We instead make a clumsy factorial: using the integers in decreasing order, we swap out the multiply operations for a fixed rotation of operations: multiply (*), divide (/), add (+) and subtract (-) in this order.

// For example, clumsy(10) = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1.  However, these operations are still applied using the usual order of operations of arithmetic: we do all multiplication and division steps before any addition or subtraction steps, and multiplication and division steps are processed left to right.

// Additionally, the division that we use is floor division such that 10 * 9 / 8 equals 11.  This guarantees the result is an integer.

// Implement the clumsy function as defined above: given an integer N, it returns the clumsy factorial of N.

 

// Example 1:

// Input: 4
// Output: 7
// Explanation: 7 = 4 * 3 / 2 + 1
// Example 2:

// Input: 10
// Output: 12
// Explanation: 12 = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1
 

// Note:

// 1 <= N <= 10000
// -2^31 <= answer <= 2^31 - 1  (The answer is guaranteed to fit within a 32-bit integer.)
// 通过次数9,308提交次数15,900

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void print(vector<vector<int>> &arr){
    for(auto & t:arr){
        for(int i:t){
            cout<<i<<",";
        }
        cout<<endl;
    }
}

class Solution {
public:
    int clumsy1(int N) {
        stack<int> st;
        st.push(N);
        N--;

        int index = 0;
        while(N>0){
            if(index%4==0){
                st.top()*=N;
            }else if(index%4==1){
                st.top()/=N;
            }else if(index%4==2){
                st.push(N);
            }else if(index%4==3){
                st.push(-N);
            }
            N--;
            index++;
        }
        int res = 0;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
    int clumsy(int N) {
        vector<int> special = {1,2,6,7};
        vector<int> diff = {1,2,2,-1};
        if(N<=4)return special[(N-1)%4];
        return N+diff[N%4];
    }
};

int main(){
    int N = 10;
    Solution s;
    int res = s.clumsy(N);
    cout<<res<<endl;
    return 0;
}