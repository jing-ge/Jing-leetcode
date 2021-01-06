// 面试题 17.06. Number Of 2s In Range LCCI
// Write a method to count the number of 2s that appear in all the numbers between 0 and n (inclusive).

// Example:

// Input: 25
// Output: 9
// Explanation: (2, 12, 20, 21, 22, 23, 24, 25)(Note that 22 counts for two 2s.)
// Note:

// n <= 10^9
// 通过次数2,988提交次数6,940

#include <iostream>


using namespace std;

class Solution {
public:
    int numberOf2sInRange2(int n) {
        int count = 0;
        for(int i=0;i<=n;i++){
            string s = to_string(i);
            for(char c:s){
                if(c=='2')count++;
            }
        }
        return count;
    }
    int numberOf2sInRange(int n) {
        if(n<=1)return 0;
        if(n<=11)return 1;
        int a = 0,b = 0,res = 0;
        for(long long i=1;i<=n;i*=10){
            a= n/i;
            b = n%i;
            res += (a+7)/10*i + (a%10==2)*(b+1);
        }
        return res;
    }
};

int main(){
    Solution s = Solution();
    int res = s.numberOf2sInRange(25);
    cout<<res<<endl;
    return 0;
}