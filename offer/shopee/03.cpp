
// 压缩字符串
// 详细描述
// 字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。比如，字符串aabcccccaaa会变为a2bc5a3。你可以假设字符串中只包含大小写英文字母（a至z）。

// 只有一个字符，1 不用写

// 要求：时间复杂度O（N）

// 其他
// 时间限制: 1000ms

// 内存限制: 256.0MB

// 输入输出示例
// 示例1
// 输入
// 复制
// "shopeew"
// 输出
// 复制
// "shope2w"

#include <vector>
#include <iostream>
#include <string>
#include <sstream>


using namespace std;



class Solution {
public:
    string compressString(string S) {
        if ((int)S.length() == 0) return S; // 空串处理
        string ans = "";
        int cnt = 1;
        char ch = S[0];
        for (int i = 1; i < (int)S.length(); ++i){
            if (ch == S[i]) cnt++;
            else{

                ans += ch ; // 注意 cnt 要转为字符串
                if(cnt>1)ans+= to_string(cnt);
                ch = S[i];
                cnt = 1;
            }
        }
        ans += ch;
        if(cnt>1)ans+= to_string(cnt);
        return ans;
    }
};



int main(){
    string str = "shopeew";
    Solution s;
    string res = s.compressString(str);
    cout<<res<<endl;
    return 0;
}