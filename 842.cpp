// 842. Split Array into Fibonacci Sequence
// Given a string S of digits, such as S = "123456579", we can split it into a Fibonacci-like sequence [123, 456, 579].

// Formally, a Fibonacci-like sequence is a list F of non-negative integers such that:

// 0 <= F[i] <= 2^31 - 1, (that is, each integer fits a 32-bit signed integer type);
// F.length >= 3;
// and F[i] + F[i+1] = F[i+2] for all 0 <= i < F.length - 2.
// Also, note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number 0 itself.

// Return any Fibonacci-like sequence split from S, or return [] if it cannot be done.

// Example 1:

// Input: "123456579"
// Output: [123,456,579]
// Example 2:

// Input: "11235813"
// Output: [1,1,2,3,5,8,13]
// Example 3:

// Input: "112358130"
// Output: []
// Explanation: The task is impossible.
// Example 4:

// Input: "0123"
// Output: []
// Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not valid.
// Example 5:

// Input: "1101111"
// Output: [110, 1, 111]
// Explanation: The output [11, 0, 11, 11] would also be accepted.
// Note:

// 1 <= S.length <= 200
// S contains only digits.


#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(vector<int>res){
    for(int i:res){
        cout<<i<<",";
    }
    cout<<endl;
}

class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> res;
        if (mydfs(0,S,res)){
            return res;
        }else{
            return {};
        }
    }
    bool dfs(string &S,int index, vector<int>& res){
        int size = res.size();
        if(index==S.size())return size>2;
        int num = 0;
        for(int i = index;i<S.size();i++){
            num = 10*num + (S[i]-'0');
            if(num<0)return false;
            if(res.size()<2||num == res[res.size()-1]+res[res.size()-2]){
                res.push_back(num);
                if(dfs(S,i+1,res))
                    return true;
                res.pop_back();
            }
            if(S[i]=='0'&&i==index){
                return false;
            }
        }
        return false;
    }

    bool mydfs(int index,string &s,vector<int>&res){
        if(index == s.size())return res.size()>2;
        int num = 0;
        for(int i=index;i<s.size();i++){
            num = 10*num + (s[i]-'0');
            if(num<0||num>=INT32_MAX)return false;
            print(res);
            if(res.size()<2||num==res[res.size()-1]+res[res.size()-2]){
                res.push_back(num);
                if(mydfs(i+1,s,res)){
                    return true;
                }
                res.pop_back();
            }
            if(s[i]=='0'&&i==index)return false;
        }
        return false;
    }
};



int main(){
    string s = "123456579";
    Solution so = Solution();
    vector<int> res = so.splitIntoFibonacci(s);
    print(res);
    return 0;
}