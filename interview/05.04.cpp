// 面试题 05.04. Closed Number LCCIGiven a positive integer, print the next smallest and the next largest number that have the same number of 1 bits in their binary representation.

// Example1:

//  Input: num = 2 (0b10)
//  Output: [4, 1] ([0b100, 0b1])
// Example2:

//  Input: num = 1
//  Output: [2, -1]
// Note:

// 1 <= num <= 2147483647
// If there is no next smallest or next largest number, output -1.
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

void print(vector<int>&nums){
    for(int i:nums){
        cout<<i<<",";
    }
    cout<<endl;
}

class Solution {
public:
    vector<int> findClosedNumbers(int num) {
        bitset<32>small(num);
        bitset<32>big(num);
        int s = -1;
        for(int i=1;i<32;i++){
            if(small[i]==1&&small[i-1]==0){
                small.flip(i);
                small.flip(i-1);
                for(int left = 0,right =i-2;left<right; ){
                    while (left<right&&small[left]==0)left++;
                    while (left<right&&small[right]==1)right--;
                    small.flip(left);
                    small.flip(right);
                }
                s = (int)small.to_ulong();
                break;
            }
        }
        int b = -1;
        for(int i=1;i<32;i++){
            if(big[i]==0&&big[i-1]==1){
                big.flip(i);
                big.flip(i-1);
                for(int left = 0,right =i-2;left<right; ){
                    while (left<right&&small[left]==1)left++;
                    while (left<right&&small[right]==0)right--;
                    small.flip(left);
                    small.flip(right);
                }
                b = (int)small.to_ulong();
                break;
            }
        }
        return {b,s};
    }
};

int main(){
    Solution s = Solution();
    int num = 2012;
    vector<int>res = s.findClosedNumbers(num);
    print(res);
    return 0;
}