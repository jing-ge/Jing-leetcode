// 本题无跳出页面限制，支持使用本地IDE调试，最终以系统调试结果为准。
// 掰花瓣
// 详细描述
// 手上有 n 朵花，每朵的花瓣数保存在一个数组中。我们每次可以选择任意一朵，拿走其中的一瓣或者两瓣，求掰完所有花的最少次数。

// 其他
// 时间限制: 1000ms

// 内存限制: 256.0MB

// 输入输出示例
// 示例1
// 输入
// 复制
// [4,2,1]
// 输出
// 复制
// 4
// 示例2
// 输入
// 复制
// [2,3,10]
// 输出
// 复制
// 8
// 示例3
// 输入
// 复制
// [0,1]
// 输出
// 复制
// 1
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * Note: 类名、方法名、参数名已经指定，请勿修改
     *
     * 
     * 
     * @param petals int整型vector 花瓣数
     * @return int整型
     */
    int petalsBreak(vector<int>& petals) {
        // write code here
        int res = 0;
        for(int i:petals){
            if(i%2==0){
                res+=i/2;
            }else{
                res+=i/2+1;
            }
        }
        return res;
    }
};

int main(){
    vector<int> petals = {0,1};
    Solution s;
    int res = s.petalsBreak(petals);
    cout<<res<<endl;
    return 0;
}
