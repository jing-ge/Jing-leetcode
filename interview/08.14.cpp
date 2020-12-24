// 面试题 08.14. Boolean Evaluation LCCI
// Given a boolean expression consisting of the symbols 0 (false), 1 (true), & (AND), | (OR), and ^ (XOR), and a desired boolean result value result, implement a function to count the number of ways of parenthesizing the expression such that it evaluates to result.

// Example 1:

// Input: s = "1^0|0|1", result = 0

// Output: 2
// Explanation: Two possible parenthesizing ways are:
// 1^(0|(0|1))
// 1^((0|0)|1)
// Example 2:

// Input: s = "0&0&0&1^1|0", result = 1

// Output: 10
// Note:

// There are no more than 19 operators in s.
// 面试题 08.13. Pile Box LCCI
// You have a stack of n boxes, with widths wi, depths di, and heights hi. The boxes cannot be rotated and can only be stacked on top of one another if each box in the stack is strictly larger than the box above it in width, height, and depth. Implement a method to compute the height of the tallest possible stack. The height of a stack is the sum of the heights of each box.

// The input use [wi, di, hi] to represents each box.

// Example1:

//  Input: box = [[1, 1, 1], [2, 2, 2], [3, 3, 3]]
//  Output: 6
// Example2:

//  Input: box = [[1, 1, 1], [2, 3, 4], [2, 6, 7], [3, 4, 5]]
//  Output: 10
// Note:

// box.length <= 3000
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countEval(string s, int result) {
        int n = s.length();
        vector<int>A;
        vector<char>opt;
        for(int i=0;i<n;i++){
            if(i&1)opt.push_back(s[i]);
            else A.push_back(s[i]-'0');
        }
        n = A.size();
        int F[n][n][2];
        for(int i=0;i<n;i++)F[i][i][A[i]]=1,F[i][i][A[i]^1]=0;
        for(int l=2;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j = i+l-1;
                F[i][j][0]=F[i][j][1] = 0;
                for(int k=i;k<j;k++){
                    if(opt[k]=='&'){
                        F[i][j][1] += F[i][k][1]*F[k+1][j][1];
                        F[i][j][0] += F[i][k][1]*F[k+1][j][0];
                        F[i][j][0] += F[i][k][0]*F[k+1][j][1];
                        F[i][j][0] += F[i][k][0]*F[k+1][j][0];
                    }
                    else if(opt[k]=='|')
                    {
                        F[i][j][1] += F[i][k][1]*F[k+1][j][1];
                        F[i][j][1] += F[i][k][1]*F[k+1][j][0];
                        F[i][j][1] += F[i][k][0]*F[k+1][j][1];
                        F[i][j][0] += F[i][k][0]*F[k+1][j][0];
                    }
                    else
                    {
                        F[i][j][0] += F[i][k][1]*F[k+1][j][1];
                        F[i][j][1] += F[i][k][1]*F[k+1][j][0];
                        F[i][j][1] += F[i][k][0]*F[k+1][j][1];
                        F[i][j][0] += F[i][k][0]*F[k+1][j][0];
                    }
                }
            }
        }
        return F[0][n-1][result];
    }
};

int main(){
    Solution s = Solution();
    string str = "1^0|0|1";
    int result = 0;
    int res = s.countEval(str,result);
    cout<<res<<endl;
    return 0;
}