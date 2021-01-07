// 面试题 17.09. Get Kth Magic Number LCCI
// Design an algorithm to find the kth number such that the only prime factors are 3, 5, and 7. Note that 3, 5, and 7 do not have to be factors, but it should not have any other prime factors. For example, the first several multiples would be (in order) 1, 3, 5, 7, 9, 15, 21.

// Example 1:

// Input: k = 5

// Output: 9

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<int>dp(k,1);
        int p3=0,p5=0,p7=0;
        for(int i=1;i<k;i++){
            dp[i] = min(min(dp[p3]*3,dp[p5]*5),dp[p7]*7);
            if(dp[i]==dp[p3]*3)p3++;
            if(dp[i]==dp[p5]*5)p5++;
            if(dp[i]==dp[p7]*7)p7++;
        }
        return dp[k-1];
    }
};

int main(){
    Solution s = Solution();
    int res = s.getKthMagicNumber(9);
    cout<<res<<endl;
    return 0;
}