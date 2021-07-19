
// 剑指 Offer 17. 打印从1到最大的n位数
// 输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

// 示例 1:

// 输入: n = 1
// 输出: [1,2,3,4,5,6,7,8,9]
 

// 说明：

// 用返回一个整数列表来代替打印
// n 为正整数
// 通过次数132,140提交次数169,678


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> printNumbers_(int n) {
        vector<int> res;
        int i = 1;
        while(to_string(i).size()<=n){
            res.push_back(i++);
        }
        return res;
    }
    vector<int> printNumbers(int n) {
        vector<int> res;
        int t = get(n);
        for(int i=1;i<=t;i++){
            res.push_back(i);
        }
        return res;
    }
    int get(int n){
        int t = 0;
        while (n)
        {
            t = t*10+9;
            n--;
        }
        return t;
    }
};

int main(){
    Solution s;
    int n =3;
    vector<int> res = s.printNumbers(n);
    for(int i:res)cout<<i<<endl;
    return 0;
}

