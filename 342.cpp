// 342. Power of Four
// Given an integer n, return true if it is a power of four. Otherwise, return false.

// An integer n is a power of four, if there exists an integer x such that n == 4x.

 

// Example 1:

// Input: n = 16
// Output: true
// Example 2:

// Input: n = 5
// Output: false
// Example 3:

// Input: n = 1
// Output: true
 

// Constraints:

// -231 <= n <= 231 - 1
// å

#include <iostream>

using namespace std;
class Solution {
public:
    bool isPowerOfFour1(int n) {
        if(n<4)return false;
        int t = n;
        while(t%4==0){
            t = t/4;
        }
        if(t==1)return true;
        else return false;
    }

    bool isPowerOfFour2(int n) {
        return n>0&&((n&(n-1))==0)&&(n%3==1);
    }    

    bool isPowerOfFour(int n){
        return n>0 && ((n&(n-1))==0) && (n&0xaaaaaaaa)==0;
    }
};

int main(){
    Solution s = Solution();
    int n = 13;
    int res = s.isPowerOfFour(n);
    cout<<res<<endl;
    return 0;
}


// n&(n-1)的用途
// 最近做LeetCode上面的题目，发现很多题目都用到了n&(n-1)。感觉真是神通广大，下面就目前所看到的一些用途总结一下：

// 1，求一个int类型数是否为2的幂

// 当n=4时，二进制为：0100

//    n-1=3，二进制为：0011

// 则：n&(n-1)==0

// 当n=8时，为1000

// n-1=7，为0111

// 则n&(n-1)==0

// 再举个反例：当n=5，为0101

// n-1为0100

// 则n&(n-1)=0100=4!=0

// 从上面我们可以看出，凡是2的幂，均是二进制数的某一高位为1，且仅此高位为1，比如4，0100；8，1000。那么它的n-1就变成了1所处的高位变成0，剩余低位变成1，如4-1,0011,8-1,0111，那么n&(n-1)必为0

// 也就是n&(n-1)==0

// 2,一个数的二进制中有多少位为1

// while（n>0）{

// count++;

// n = n&(n-1);

// }

// 这个原理有点类似于2的幂，大家可以自己动手试试，文字的解释永远无法战胜自己的亲身实践

// 3，一个数是否为4的幂

// 一个数是4的幂，那么必然是2的幂，反之，则不然

// 那么首先确定条件n&（n-1）==0，确定出该数是否为2的幂，这就找到了一项必要条件

// 刚才说了一个数是2的幂却不一定是4的幂，比如2,8,32等这些都是2的级数次方

// 但是，我们可以发现，2的偶数次方，比如2^0=1,2^2=4,2^4=16,这些数减去1，都能被3整除，而2的奇数次方的数减去1之后无法被3整除，不信可以试试

// 这样的话，我们就可以很容易找到4的幂的充要条件，即 n>0 && ((n&(n-1))==0) && ((n-1)%3==0)

// 4,接下来还有一些可以用到符号&运算的例子，比如求一个数32位二进制的倒序

// int result =0；

// for（int i=0；i<32；i++）{

//        result<<=1;//result先左移一位，低位补0

//        result = result+(n&1)；

//      n>>=1;//n右移一位，高位补0

// }

// 5，将一个数表示为16进制,并返回相应字符串

// if(n==0) return "0";

// String  result =""；

// String[] map={"0"，"1"，"2"，"3"，"4"，"5"，"6"，"7"，"8"，"9"，"a"，"b"，"c"，"d"，"e"，"f"};

// while（n!=0）{

// result = map[n&15]+result;

// n>>=4;

// }

// 好了，暂时就这么多，以后遇到了再补上。