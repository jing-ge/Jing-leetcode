// 753. Cracking the Safe
// There is a box protected by a password. The password is a sequence of n digits where each digit can be one of the first k digits 0, 1, ..., k-1.

// While entering a password, the last n digits entered will automatically be matched against the correct password.

// For example, assuming the correct password is "345", if you type "012345", the box will open because the correct password matches the suffix of the entered password.

// Return any password of minimum length that is guaranteed to open the box at some point of entering it.

 

// Example 1:

// Input: n = 1, k = 2
// Output: "01"
// Note: "10" will be accepted too.
// Example 2:

// Input: n = 2, k = 2
// Output: "00110"
// Note: "01100", "10011", "11001" will be accepted too.
 

// Note:

// n will be in the range [1, 4].
// k will be in the range [1, 10].
// k^n will be at most 4096.
 

// 通过次数2,181提交次数3,863
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    string crackSafe(int n, int k) {
        int kn = pow(k, n), kn_1 = pow(k, n-1);//将所有n-1位数作为节点的节点个数
        vector<int> num(kn_1,k-1);//表示k^(n-1)个节点的下一位可以从k-1选到0，当前索引处对应的元素值表示该节点已经把比元素值大的值都作为下一数字添加过了
        string s(kn + (n-1), '0');//字符串初始化，（结果一定是kn+n-1位）
        for(int i = n-1, node = 0; i < s.size(); ++i) {//i从n-1开始递增 （第一个密码是n-1个0（00...为起始点））
            s[i] = num[node]-- + '0';//更新字符串。先运算 再--，表示下一次该节点要选的下一数字
            node = node*k - (s[i-(n-1)]-'0')*kn_1 + num[node] + 1;//更新当前节点。
            //左移操作：1.*k,2.减去左侧超出的一位代表的数字（这位数字已经到了k^(n-1)上，所以后面×一个k(n-1)）,3.加上右边进来的新数字(刚才-1用于下次的选路径，但这次的节点还没更新呢，要把这个1加回来)
        }
        return s;
    }
};
int main(){
    Solution s;
    int n=1,k=2;
    string res = s.crackSafe(n,k);
    cout<<res<<endl;
    return 0;
}