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


class Solution {
public:
    int i;
    string str;
    string countOfAtoms(string formula) {
        i = 0;
        str = formula;
        map<string,int> mymap = parse();
        string res;
        for(auto t:mymap){
            res+=t.first;
            // if(t.second>1){
                res+=to_string(t.second);
            // }
        }
        return res;
    }
    map<string,int> parse(){
        map<string,int> mymap;
        int N = str.size();
        while(i<N && str[i]!=')'){
            if(str[i]=='('){
                i++;
                for(auto &t:parse()){
                    mymap[t.first]+=t.second;
                }
            }else{
                int start = i;
                i++;
                while(i<N&&str[i]>='a'&&str[i]<='z')i++;
                string name = str.substr(start,i-start);
                start = i;
                while(i<N&&str[i]>='0'&&str[i]<='9')i++;
                if(start==i){
                    mymap[name]++;
                }else{
                    mymap[name]+=stoi(str.substr(start,i-start));
                }
            }
        }
        i++;
        int start = i;
        while(i<N&&str[i]>='0'&&str[i]<='9')i++;
        if(start<i){
            int mulp = stoi(str.substr(start,i-start));
            for(auto &t:mymap){
                mymap[t.first]*=mulp;
            }
        }
        return  mymap;
    }
};

int main(){
    Solution s;
    string str;
    cin>>str;
    for(int i=0;i<str.size();i++){
        if(str[i]=='[')str[i]='(';
        else if(str[i]==']')str[i]=')';
    }
    string res =s.countOfAtoms(str);
    cout<<res<<endl;
    return 0;
}