// 402. Remove K Digits
// Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

// Note:
// The length of num is less than 10002 and will be ≥ k.
// The given num does not contain any leading zero.
// Example 1:

// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
// Example 2:

// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
// Example 3:

// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with nothing which is 0.

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k>=num.size())return "0";
        int remain = k;
        k = num.size()-k;
        string res(k,'0');
        int top = -1;
        for(int i = 0;i<num.size();i++){
            char c = num[i];
            while(top>=0 && res[top]>c && remain > 0){
                top--;
                remain--;
            }
            if(top<k-1){  
                res[++top] = c;
            }else{
                remain--;
            }
        }
        int c = 0;
        while ((res.size()-c>1)&&res[c]=='0')
        {
            c++;
        }
        res = res.substr(c,res.size()-c);
        
        return res;
    }
};

int main(){
    Solution s = Solution();
    string num = "10200";
    int k = 1;
    string res = s.removeKdigits(num,k);
    // cout<<"-----------"<<endl;
    cout<<res<<endl;
    return 0;
}