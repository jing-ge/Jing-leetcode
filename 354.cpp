// 354. Russian Doll Envelopes
// You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

// What is the maximum number of envelopes can you Russian doll? (put one inside other)

// Note:
// Rotation is not allowed.

// Example:

// Input: [[5,4],[6,4],[6,7],[2,3]]
// Output: 3 
// Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
// 通过次数28,022提交次数70,383

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxEnvelopes1(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if(n==0)return 0;
        sort(envelopes.begin(),envelopes.end(),[](const vector<int>&a,const vector<int> &b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }else{
                return a[0]<b[0];
            }
        });
        vector<int> f(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(envelopes[j][1]<envelopes[i][1])
                    f[i] = max(f[i], f[j]+1);
            }
        }
        return *max_element(f.begin(),f.end());
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if(n==0)return 0;
        sort(envelopes.begin(),envelopes.end(),[](const vector<int>&a,const vector<int> &b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }else{
                return a[0]<b[0];
            }
        });
        
        vector<int> f = {envelopes[0][1]};
        for(int i=1;i<n;i++){
            int num = envelopes[i][1];
            if(num>f.back()){
                f.push_back(num);
            }else{
                auto it = lower_bound(f.begin(),f.end(),num);
                *it = num;
            }
        }
        return f.size();
    }
};

int main(){
    Solution s;
    // vector<vector<int>> envelopes = {{5,4},{6,4},{6,7},{2,3}};
    vector<vector<int>> envelopes = {{46,89},{50,53},{52,68},{72,45},{77,81}};
    int res = s.maxEnvelopes(envelopes);
    cout<<res<<endl;
    return 0;
}