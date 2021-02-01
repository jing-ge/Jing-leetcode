// 古生物血缘远近判定
// DNA 是由 ACGT 四种核苷酸组成，例如 AAAGTCTGAC，假定自然环境下 DNA 发生异变的情况有：

// 基因缺失一个核苷酸
// 基因新增一个核苷酸
// 基因替换一个核苷酸
// 且发生概率相同。
// 古生物学家 Sam 得到了若干条相似 DNA 序列，Sam 认为一个 DNA 序列向另外一个 DNA 序列转变所需的最小异变情况数可以代表其物种血缘相近程度，异变情况数越少，血缘越相近，请帮助 Sam 实现获取两条 DNA 序列的最小异变情况数的算法。

// 输入描述:

// 每个样例只有一行，两个 DNA 序列字符串以英文逗号“,”分割
// 输出描述:
// 输出转变所需的最少情况数，类型是数字

// 测试用例:
// 输入
// ACT,AGCT
// 输出
// 1

// 数据范围：

// 每个 DNA 序列不超过 100 个字符

// 作者：字节校园
// 链接：https://leetcode-cn.com/leetbook/read/bytedance-c01/eug83v/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        int **dp = new int*[m+1];
        for(int i=0;i<=m;i++){
            dp[i] = new int[n+1];
        }
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0){
                    dp[i][j] = j;
                }else if(j==0){
                    dp[i][j] = i;
                }else{
                    dp[i][j]=0;
                }
            }
        }

        //dp
        int min;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(word1[i]==word2[j]){
                    min = mymin(dp[i][j]-1,dp[i+1][j],dp[i][j+1]);
                }else{
                    min = mymin(dp[i][j],dp[i+1][j],dp[i][j+1]);
                }
                dp[i+1][j+1] = min+1;
            }
        }


        // for(int i=0;i<=m;i++){
        //     for(int j=0;j<=n;j++){
        //         cout<<dp[i][j]<<'\t';
        //     }
        //     cout<<endl;
        // }
        return dp[m][n];
    }
    int mymin(int a,int b,int c){
        int min;
        min = a<b?a:b;
        min = min<c?min:c;
        return min;
    }
};

int main(){
    string s,word1,word2;
    cin>>s;
    int i=0;
    while(i<s.size()){
        if(s[i]==',')break;
        i++;
    }
    word1 = s.substr(0,i);
    word2 = s.substr(i+1,s.size()-i-1);
    Solution sol;
    int res = sol.minDistance(word1,word2);
    cout<<res<<endl;
    return 0;
}