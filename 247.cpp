// 274. H-Index
// Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return compute the researcher's h-index.

// According to the definition of h-index on Wikipedia: A scientist has an index h if h of their n papers have at least h citations each, and the other n − h papers have no more than h citations each.

// If there are several possible values for h, the maximum one is taken as the h-index.

 

// Example 1:

// Input: citations = [3,0,6,1,5]
// Output: 3
// Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
// Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.
// Example 2:

// Input: citations = [1,3,1]
// Output: 1
 

// Constraints:

// n == citations.length
// 1 <= n <= 5000
// 0 <= citations[i] <= 1000


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int h = 0,i = citations.size()-1;
        while (i>=0&&citations[i]>h){
            h++;
            i--;
        }
        return h;
    }
    int hIndex_(vector<int>& citations) {
        int h = 0,n = citations.size(),total = 0;
        vector<int> counter(n+1);
        for(int i=0;i<n;i++){
            if(citations[i]>=n){
                counter[n]++;
            }else{
                counter[citations[i]]++;
            }
        }
        for(int i=n;i>=0;i--){
            total+=counter[i];
            if(total>=i)return i;
        }
        return 0;
    }
};

int main(){
    vector<int> citations = {3,0,6,1,5};
    Solution s;
    int res = s.hIndex(citations);
    cout<<res<<endl;
    return 0;
}