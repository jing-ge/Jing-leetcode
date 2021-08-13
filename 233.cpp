// 233. Number of Digit One
// Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

 

// Example 1:

// Input: n = 13
// Output: 6
// Example 2:

// Input: n = 0
// Output: 0
 

// Constraints:

// 0 <= n <= 109
// 通过次数21,548提交次数49,311

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countDigitOne_(int n) {
        int res = 0;
        for(int i=1;i<=n;i++){
            string s = to_string(i);
            for(char c:s){
                if(c=='1')res++;
            }
        }
        return res;
    }
    int countDigitOne(int n) {
        int mul = 1;
        int res = 0;
        while (mul<=n)
        {
            res+= (n/(mul*10))*mul + min(max(n%(mul*10)-mul+1,0),mul);
            mul*=10;
        }
        
        return res;
    }
};

int main(){
    Solution s;
    int n = 13;
    int res = s.countDigitOne(n);
    cout<<res<<endl;
    return 0;
}