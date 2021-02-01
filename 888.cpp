// 888. Fair Candy Swap
// Alice and Bob have candy bars of different sizes: A[i] is the size of the i-th bar of candy that Alice has, and B[j] is the size of the j-th bar of candy that Bob has.

// Since they are friends, they would like to exchange one candy bar each so that after the exchange, they both have the same total amount of candy.  (The total amount of candy a person has is the sum of the sizes of candy bars they have.)

// Return an integer array ans where ans[0] is the size of the candy bar that Alice must exchange, and ans[1] is the size of the candy bar that Bob must exchange.

// If there are multiple answers, you may return any one of them.  It is guaranteed an answer exists.

 

// Example 1:

// Input: A = [1,1], B = [2,2]
// Output: [1,2]
// Example 2:

// Input: A = [1,2], B = [2,3]
// Output: [1,2]
// Example 3:

// Input: A = [2], B = [1,3]
// Output: [2,3]
// Example 4:

// Input: A = [1,2,5], B = [2,4]
// Output: [5,4]
 

// Note:

// 1 <= A.length <= 10000
// 1 <= B.length <= 10000
// 1 <= A[i] <= 100000
// 1 <= B[i] <= 100000
// It is guaranteed that Alice and Bob have different total amounts of candy.
// It is guaranteed there exists an answer.
// 通过次数26,927提交次数44,055

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = 0, sumB = 0;
        for(int &a:A)sumA+=a;
        for(int &b:B)sumB+=b;
        int dif = (sumB-sumA)/2;
        unordered_set<int> s(B.begin(),B.end());
        for(int &x:A){
            if(s.count(x+dif)!=0)return {x,x+dif};
        }
        return {-1,-1};
    }
};

int main(){
    vector<int> A = {1,2,5},B = {2,4};
    Solution s;
    vector<int> res = s.fairCandySwap(A,B);
    cout<<res[0]<<","<<res[1]<<endl;
    return 0;
}