// 372. Super Pow

// Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

//  

// Example 1:

// Input: a = 2, b = [3]
// Output: 8
// Example 2:

// Input: a = 2, b = [1,0]
// Output: 1024
// Example 3:

// Input: a = 1, b = [4,3,3,8,5,2]
// Output: 1
// Example 4:

// Input: a = 2147483647, b = [2,0,0]
// Output: 1198


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int base = 1337;
    int mypow(int a, int k){
        if(k==0)return 1;
        a %= base;
        if(k%2==1){
            return (a*mypow(a,k-1))%base;
        }else{
            int sub = mypow(a,k/2);
            return (sub*sub)%base;
        }
    }
    int superPow(int a, vector<int>& b) {
        if(b.empty())return 1;
        int last = b.back();
        b.pop_back();
        int part1 = mypow(a,last);
        int part2 = mypow(superPow(a,b),10);
        return (part1*part2)%base;
    }
};

int main(){
    Solution s = Solution();
    int a = 2;
    vector<int> b = {4,3,3,8,5,2};
    int res = s.superPow(a,b);
    cout<<res<<endl;
    return 0;
}