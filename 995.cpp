// 995. Minimum Number of K Consecutive Bit Flips
// In an array A containing only 0s and 1s, a K-bit flip consists of choosing a (contiguous) subarray of length K and simultaneously changing every 0 in the subarray to 1, and every 1 in the subarray to 0.

// Return the minimum number of K-bit flips required so that there is no 0 in the array.  If it is not possible, return -1.

 

// Example 1:

// Input: A = [0,1,0], K = 1
// Output: 2
// Explanation: Flip A[0], then flip A[2].
// Example 2:

// Input: A = [1,1,0], K = 2
// Output: -1
// Explanation: No matter how we flip subarrays of size 2, we can't make the array become [1,1,1].
// Example 3:

// Input: A = [0,0,0,1,0,1,1,0], K = 3
// Output: 3
// Explanation:
// Flip A[0],A[1],A[2]: A becomes [1,1,1,1,0,1,1,0]
// Flip A[4],A[5],A[6]: A becomes [1,1,1,1,1,0,0,0]
// Flip A[5],A[6],A[7]: A becomes [1,1,1,1,1,1,1,1]
 

// Note:

// 1 <= A.length <= 30000
// 1 <= K <= A.length
// 通过次数6,781提交次数13,918

#include <vector>
#include <iostream>
#include <queue>

using namespace std;
void print(vector<int> &A){
    for(int &i:A)cout<<i<<",";
    cout<<endl;
}

class Solution {
public:
    // 使用队列
    int minKBitFlips1(vector<int>& A, int K) {
        int res = 0,cur = 0;
        queue<int>q;
        for(int i=0;i<A.size();i++){
            while(!q.empty()&&q.front()<=i-K)q.pop();
            // cout<<i<<endl;
            // cout<<q.size()<<endl;
            if(q.size()%2)A[i] = A[i]?0:1;
            // print(A);
            if(A[i]==0){
                if(i+K>A.size())return -1;
                q.push(i);
                A[i] = 1;
                res++;
            }
        }
        return res;
    }
    //使用计数
    int minKBitFlips(vector<int>& A, int K) {
        int res = 0,cur = 0;
        queue<int>q;
        for(int i=0;i<A.size();i++){
            if(i-K>=0&&A[i-K]>1){
                A[i-K] -= 2;
                cur--;
            }
            if(cur%2==A[i]){
                if(i+K>A.size())return -1;
                A[i]+=2;
                cur++;
                res++;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> A = {0,0,0,1,0,1,1,0};
    int res = s.minKBitFlips(A,3);
    cout<<res<<endl;
    return 0;
}