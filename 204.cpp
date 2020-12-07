// 204. Count Primes
// Count the number of prime numbers less than a non-negative number, n.

//  

// Example 1:

// Input: n = 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
// Example 2:

// Input: n = 0
// Output: 0
// Example 3:

// Input: n = 1
// Output: 0

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int countPrimes(int n) {
        if (n<2)return 0;
       vector<bool> arr(n,true);
       for(int i = 2;i*i<n;i++){
           if(isPrime(i)){
               for(int j = i*i;j<n;j+=i){
                   arr[j] = false;
               }
           }
       }
       int cnt = 0;
       for(int i = 2;i<n;i++){
           if(arr[i])cnt++;
       }
       return cnt;
    }

    bool isPrime(int n){
        for(int i = 2;i*i<n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution s = Solution();
    int res = s.countPrimes(499979);
    cout<<"res:"<<res<<endl;
    return 0;
}
