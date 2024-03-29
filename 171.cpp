// 171. Excel Sheet Column Number
// Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.

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

// Input: columnTitle = "A"
// Output: 1
// Example 2:

// Input: columnTitle = "AB"
// Output: 28
// Example 3:

// Input: columnTitle = "ZY"
// Output: 701
// Example 4:

// Input: columnTitle = "FXSHRXW"
// Output: 2147483647
 

// Constraints:

// 1 <= columnTitle.length <= 7
// columnTitle consists only of uppercase English letters.
// columnTitle is in the range ["A", "FXSHRXW"].
// 通过次数73,610提交次数106,056


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res=0;
        for(char &c:columnTitle){
            res = res*26+(c-'A'+1);
        }
        return res;
    }
    string numberToTitle(int n){
        string res;
        while (n>26)
        {
            res.push_back(n%26+'A'-1);
            n = n/26;
        }
        res.push_back(n+'A'-1);
        reverse(res.begin(),res.end());
        return res;
    }
};

int main(){
    string columnTitle = "FFBSS";
    Solution s;
    int res = s.titleToNumber(columnTitle);
    cout<<res<<endl;
    string t = s.numberToTitle(res);
    cout<<t<<endl;
    return 0;
}