// 168. Excel Sheet Column Title
// Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

// For example:

// A -> 1
// B -> 2
// C -> 3
// ...
// Z -> 26
// AA -> 27
// AB -> 28 
// ...
 

// Example 1:

// Input: columnNumber = 1
// Output: "A"
// Example 2:

// Input: columnNumber = 28
// Output: "AB"
// Example 3:

// Input: columnNumber = 701
// Output: "ZY"
// Example 4:

// Input: columnNumber = 2147483647
// Output: "FXSHRXW"
 

// Constraints:

// 1 <= columnNumber <= 231 - 1
// 通过次数55,966提交次数139,453


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        int temp = columnNumber;
        while(temp--){
            int yu = temp%26;
            temp /= 26;
            res = (char)(yu+'A')+ res;
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 701;
    string res = s.convertToTitle(n);
    cout<<res<<endl;
    return 0;
}