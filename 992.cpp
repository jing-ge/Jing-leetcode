// 992. Subarrays with K Different Integers
// Given an array A of positive integers, call a (contiguous, not necessarily distinct) subarray of A good if the number of different integers in that subarray is exactly K.

// (For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)

// Return the number of good subarrays of A.

 

// Example 1:

// Input: A = [1,2,1,2,3], K = 2
// Output: 7
// Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
// Example 2:

// Input: A = [1,2,1,3,4], K = 3
// Output: 3
// Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
 

// Note:

// 1 <= A.length <= 20000
// 1 <= A[i] <= A.length
// 1 <= K <= A.length
// 通过次数11,143提交次数29,063

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    //TLE
    int subarraysWithKDistinct1(vector<int>& A, int K) {
        unordered_set<int> s;
        int left = 0,right = 0;
        int res = 0;
        while (left<=right&&left<A.size())
        {
            s.clear();
            s = unordered_set<int>(A.begin()+left,A.begin()+right+1);
            // cout<<left<<","<<right<<endl;
            if(s.size()>K||right==A.size()-1){left++;right = left;}
            else right++;
            if(s.size()==K){res++;}
            // cout<<"res:"<<res<<endl;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& A, int K) {
        unordered_map<int,int> map1,map2;
        int left1 = 0,left2 = 0,right = 0;
        int res = 0;
        int tol1 = 0,tol2 = 0;
        while(right<A.size()){
            if(!map1[A[right]]){
                tol1++;
            }
            map1[A[right]]++;
            if(!map2[A[right]]){
                tol2++;
            }
            map2[A[right]]++;
            while(tol1>K){
                map1[A[left1]]--;
                if(!map1[A[left1]])tol1--;
                left1++;
            }
            while(tol2>K-1){
                map2[A[left2]]--;
                if(!map2[A[left2]])tol2--;
                left2++;
            }
            cout<<left1<<","<<left2<<","<<right<<endl;
            res+= left2 - left1;
            right++;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> A = {2,1,2,1,2};
    int K = 2;
    int res =s.subarraysWithKDistinct(A,K);
    cout<<res<<endl;
    return 0;
}