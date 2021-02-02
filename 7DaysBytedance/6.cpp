// 化学公式解析
// 给定一个用字符串展示的化学公式，计算每种元素的个数。
// 规则如下：

// 元素命名采用驼峰命名，例如 Mg
// () 代表内部的基团，代表阴离子团
// [] 代表模内部链节通过化学键的连接，并聚合
// 例如：H2O => H2O1 Mg(OH)2 => H2Mg1O2

// 输入描述:
// 化学公式的字符串表达式，例如：K4[ON(SO3)2]2

// 输出描述:
// 元素名称及个数：K4N2O14S4，并且按照元素名称升序排列

// 测试用例
// 输入
// K4[ON(SO3)2]2
// 输出
// K4N2O14S4

// 作者：字节校园
// 链接：https://leetcode-cn.com/leetbook/read/bytedance-c01/euzitj/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution{
public:
    string cham(string s){
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')s[i]='[';
            else if(s[i]==')')s[i]=']';
        }
        cout<<s<<endl;
        return "";
    }
    map<string,int> parse(string s){
        int i=0,j=0;
        int m=0,n=0;
        map<string,int> res;
        while(j<s.size()&&n<s.size()){
            
        }
        
    }
};

int main(){
    Solution s;
    string str;
    cin>>str;
    string res =s.cham(str);
    cout<<res<<endl;
    return 0;
}