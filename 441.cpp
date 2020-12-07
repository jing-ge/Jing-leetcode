// 441. Arranging Coins
// You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

// Given n, find the total number of full staircase rows that can be formed.

// n is a non-negative integer and fits within the range of a 32-bit signed integer.

// Example 1:

// n = 5

// The coins can form the following rows:
// ¤
// ¤ ¤
// ¤ ¤

// Because the 3rd row is incomplete, we return 2.
// Example 2:

// n = 8

// The coins can form the following rows:
// ¤
// ¤ ¤
// ¤ ¤ ¤
// ¤ ¤

// Because the 4th row is incomplete, we return 3.

#include <iostream>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int left = 1,right = n;
        while(left<=right){
            int mid = left + (right-left)/2;
            long long sum = mid*(1+mid)/2;
            if(sum==n){
                return mid;
            }else if (sum>n){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return right;
    }

    int mathsolution(int n){
        return static_cast<int>(sqrt(2 * (long)n + 0.25) - 0.5);
    }
};

int main(){
    Solution s = Solution();
    int res = s.arrangeCoins(1804289383);
    cout<<"----------"<<endl;
    cout<<res<<endl;
    return 0;
}
