// 剑指 Offer 16. 数值的整数次方
// 实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数问题。

 

// 示例 1：

// 输入：x = 2.00000, n = 10
// 输出：1024.00000
// 示例 2：

// 输入：x = 2.10000, n = 3
// 输出：9.26100
// 示例 3：

// 输入：x = 2.00000, n = -2
// 输出：0.25000
// 解释：2-2 = 1/22 = 1/4 = 0.25
 

// 提示：

// -100.0 < x < 100.0
// -231 <= n <= 231-1
// -104 <= xn <= 104
 

// 注意：本题与主站 50 题相同：https://leetcode-cn.com/problems/powx-n/

// 通过次数105,377提交次数313,125

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(x==1)return 1;
        int i = n;
        double res = 1.0;
        while (n)
        {
            if(n&1)res *=x;
            x*=x;
            n = n/2;
        }
        return i>0?res:1/res;
    }
};

int main(){
    double x = 2.1;
    int n = 3;
    Solution s;
    double res = s.myPow(x,n);
    cout<<res<<endl;
    return 0;
}