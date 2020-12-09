// 8. String to Integer (atoi)
// Implement atoi which converts a string to an integer.

// The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

// The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

// If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

// If no valid conversion could be performed, a zero value is returned.

// Note:

// Only the space character ' ' is considered a whitespace character.
// Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, 231 − 1 or −231 is returned.
//  

// Example 1:

// Input: str = "42"
// Output: 42
// Example 2:

// Input: str = "   -42"
// Output: -42
// Explanation: The first non-whitespace character is '-', which is the minus sign. Then take as many numerical digits as possible, which gets 42.
// Example 3:

// Input: str = "4193 with words"
// Output: 4193
// Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
// Example 4:

// Input: str = "words and 987"
// Output: 0
// Explanation: The first non-whitespace character is 'w', which is not a numerical digit or a +/- sign. Therefore no valid conversion could be performed.
// Example 5:

// Input: str = "-91283472332"
// Output: -2147483648
// Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer. Thefore INT_MIN (−231) is returned.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long res = 0;
        int i;
        for(i=0;i<s.size();i++){
            if(s[i]!=' ')break;
        }
        int flag=0;
        int cnt = 0;
        while(s[i]=='+'||s[i]=='-'){
            if(s[i]=='+'){
                flag++;
            }else{
                flag--;
            }
            i++;
            cnt++;
        }
        if(cnt>1)return 0;

        
        if(!(s[i]>='0'&&s[i]<='9'))return 0;

        for(;i<s.size();i++){
            char c = s[i];
            if(c<='9'&&c>='0'){
                res = 10*res +(c-'0');
                long t = flag>=0?res:-res;
                if(t>INT32_MAX)return INT32_MAX;
                if(t<INT32_MIN)return INT32_MIN;
            }else{
                break;
            }
        }
        res = flag>=0?res:-res;
        if(res>INT32_MAX)res = INT32_MAX;
        if(res<INT32_MIN)res = INT32_MIN;
        return res;
    }
};

int main(){
    Solution s = Solution();
    string str = "-91283472332";
    int res = s.myAtoi(str);
    cout<<res<<endl;
    return 0;
}