// 面试题 16.08. English Int LCCI
// Given any integer, print an English phrase that describes the integer (e.g., "One Thousand Two Hundred Thirty Four").

// Example 1:

// Input: 123
// Output: "One Hundred Twenty Three"
// Example 2:

// Input: 12345
// Output: "Twelve Thousand Three Hundred Forty Five"
// Example 3:

// Input: 1234567
// Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
// Example 4:

// Input: 1234567891
// Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
// 通过次数1,304提交次数3,577
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    const int N[31] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,30,40,50,60,70,80,90,100,1000,1000000,1000000000};
    const string S[31] = {"One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen","Twenty","Thirty","Forty","Fifty","Sixty","Senventy","Eighty","Ninety","Hundred","Thousand","Million","Billion"};
    const int K=90;
    string numberToWords(int num) {
        if(num==0)return "Zero";
        int i=30;
        while(i>=0&&N[i]>num)--i;
        string res;
        if(N[i]<=K){
            res+=S[i];
        }else{
            res += numberToWords(num/N[i])+ " " +S[i] ;
        }
        if(num%N[i]>0)res+= " " + numberToWords(num%N[i]);
        return res;
    }
};

int main(){
    Solution s = Solution();
    string res = s.numberToWords(12345);
    cout<<res<<endl;
    return 0;
}