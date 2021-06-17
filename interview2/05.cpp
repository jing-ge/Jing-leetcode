// 剑指 Offer 05. 替换空格 LCOF
// English description is not available for the problem. Please switch to Chinese.

// 通过次数217,564提交次数285,293

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string res = "";
        for(char &c:s){
            if(c==' '){
                res += "%20";
            }else{
                res += c;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    string str = "We are happy.";
    string res = s.replaceSpace(str);
    cout<<res<<endl;
    return 0;
}