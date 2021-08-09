// 313. Super Ugly Number
// A super ugly number is a positive integer whose prime factors are in the array primes.

// Given an integer n and an array of integers primes, return the nth super ugly number.

// The nth super ugly number is guaranteed to fit in a 32-bit signed integer.

 

// Example 1:

// Input: n = 12, primes = [2,7,13,19]
// Output: 32
// Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 super ugly numbers given primes = [2,7,13,19].
// Example 2:

// Input: n = 1, primes = [2,3,5]
// Output: 1
// Explanation: 1 has no prime factors, therefore all of its prime factors are in the array primes = [2,3,5].
 

// Constraints:

// 1 <= n <= 106
// 1 <= primes.length <= 100
// 2 <= primes[i] <= 1000
// primes[i] is guaranteed to be a prime number.
// All the values of primes are unique and sorted in ascending order.
// 通过次数24,670提交次数37,249

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber_heap(int n, vector<int>& primes) {
        unordered_set<long> s;
        priority_queue<long,vector<long>,greater<long>> heap;
        s.insert(1L);
        heap.push(1L);
        long tmp ;
        for(int i=0;i<n;i++){
            tmp = heap.top();
            heap.pop();
            for(int t:primes){
                long next = tmp*t;
                if(!s.count(next)){
                    s.insert(next);
                    heap.push(next);
                }
            }
        }
        return tmp;
    }
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n+1);
        int m = primes.size();
        vector<int> pointer(m,1);
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            int t = INT32_MAX;
            vector<int> tmp(m);
            for(int j=0;j<m;j++){
                tmp[j] = dp[pointer[j]]*primes[j];
                t = min(t,tmp[j]);
            }
            dp[i] = t;
            for(int k=0;k<m;k++){
                if(tmp[k]==t){
                    pointer[k]++;
                }
            }
        }
        return dp[n];
    }
};

int main(){
    Solution s;
    int n = 12;
    vector<int> primes = { 2,7,13,19};
    int res = s.nthSuperUglyNumber(n,primes);
    cout<<res<<endl;
    return 0;
}