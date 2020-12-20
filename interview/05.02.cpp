// 面试题 05.01. Insert Into Bits LCCIYou are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a method to insert M into N such that M starts at bit j and ends at bit i. You can assume that the bits j through i have enough space to fit all of M. That is, if M = 10011, you can assume that there are at least 5 bits between j and i. You would not, for example, have j = 3 and i = 2, because M could not fully fit between bit 3 and bit 2.

// Example1:

//  Input: N = 10000000000, M = 10011, i = 2, j = 6
//  Output: N = 10001001100
// Example2:

//  Input:  N = 0, M = 11111, i = 0, j = 4
//  Output: N = 11111


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string printBin(double num) {
        if(num>=1||num<=0)return "ERROR";
        string res = "0.";
        while(num>0){
            if(res.length()>32)return "ERROR";
            double r = num*2;
            if(r>=1){
                res+="1";
                num = r-1;
            }else{
                res += "0";
                num = r;
            }
        }
        return res;
    }
    string printBin2(double num) {
        if(num>=1||num<=0)return "ERROR";
        string res = "0.";
        double frac = 0.5;

        while(num>0){
            if(res.length()>32)return "ERROR";
            if(num>=frac){
                res+="1";
                num -= frac;
            }else{
                res+="0";
            }
            frac/=2;
        }
        return res;
    }
};

int main(){
    double num = 0.625;
    Solution s = Solution();
    string res = s.printBin2(num);
    cout<<res<<endl;
    return 0;
}