// 面试题 16.05. Factorial Zeros LCCI
// Write an algorithm which computes the number of trailing zeros in n factorial.

// Example 1:

// Input: 3
// Output: 0
// Explanation: 3! = 6, no trailing zero.
// Example 2:

// Input: 5
// Output: 1
// Explanation: 5! = 120, one trailing zero.
// Note: Your solution should be in logarithmic time complexity.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        /*
         0 是由 *10 得到的，而 10 是由 2 * 5 得到的
         因此我们求 n！ 过程中存在多少个 2 * 5
         因为 2 的个数必定比 5 的个数多，因此我们只求 5 的个数

         如果直接一个一个遍历，即 
         for(int i = 5; i <= n; i++){
            int temp = i;
            while(temp % 5 == 0){
                count++;
                temp /= 5;
            }
        }
        那么 n 过大时，从 1 遍历到 n, 那么会超时,因此我们修改下规律

        n! = 1 * 2 * 3 * 4 * (1 * 5) * ... * (2 * 5) * ... * (3 * 5) ...
        我们发现，
        每隔 5 个数就会出现 一个 5，因此我们只需要通过 n / 5 来计算存在存在多少个 5 个数，那么就对应的存在多少个 5
        但是，我们也会发现
        每隔 25 个数会出现 一个 25， 而 25 存在 两个 5，我们上面只计算了 25 的一个 5，因此我们需要 n / 25 来计算存在多少个 25，加上它遗漏的 5
        同时，我们还会发现
        每隔 125 个数会出现一个 125，而 125 存在 三个 5，我们上面只计算了 125 的两个 5，因此我们需要 n / 125 来计算存在多少个 125，加上它遗漏的 5
        ...

        因此我们 count = n / 5 + n / 25 + n / 125 + ...
        最终分母可能过大溢出，上面的式子可以进行转换

        count = n / 5 + n / 5 / 5 + n / 5 / 5 / 5 + ...
        因此，我们这样进行循环
        n /= 5;
        count += n;
        这样，第一次加上的就是 每隔 5 个数的 5 的个数，第二次加上的就是 每隔 25 个数的 5 的个数 ...
        */
        int count = 0;
        while(n >= 5){
            n /= 5;
            count += n;
        }
        return count;
    }
};

int main(){
    Solution s = Solution();
    int res = s.trailingZeroes(120);
    cout<<res<<endl;
    return 0;
}