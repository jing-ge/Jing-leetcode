// 738. Monotone Increasing Digits
// Given a non-negative integer N, find the largest number that is less than or equal to N with monotone increasing digits.

// (Recall that an integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.)

// Example 1:
// Input: N = 10
// Output: 9
// Example 2:
// Input: N = 1234
// Output: 1234
// Example 3:
// Input: N = 332
// Output: 299

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        int i = 1;
        while(i<s.length()&&s[i-1]<=s[i]){
            i+=1;
        }
        if(i<s.length()){
            while (i>0&&s[i-1]>s[i])
            {
                s[i-1]--;
                i--;
            }
            for(i+=1;i<s.length();i++){
                s[i] = '9';
            }
        }
        return stoi(s);
    }
};

int main(){
    Solution s = Solution();
    int N = 332;
    int res = s.monotoneIncreasingDigits(N);
    cout<<res<<endl;
    return 0;
}