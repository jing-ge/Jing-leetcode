// 172. 阶乘后的零
// 给定一个整数 n，返回 n! 结果尾数中零的数量。

// 示例 1:

// 输入: 3
// 输出: 0
// 解释: 3! = 6, 尾数中没有零。
// 示例 2:

// 输入: 5
// 输出: 1
// 解释: 5! = 120, 尾数中有 1 个零.
// 说明: 你算法的时间复杂度应为 O(log n) 。

// 作者：字节校园
// 链接：https://leetcode-cn.com/leetbook/read/bytedance-c01/ei6om6/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    int trailingZeroes(int n) {
        if(n<5)return 0;
        int res = 0;
        int t = 5;
        while(t<=n){
            res += n/t;
            t = t*5;
        }
        return res;
    }
};