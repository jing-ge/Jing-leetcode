#include <iostream>
#include <vector>
#include <string>

using namespace std;
void print(vector<long> &t){
    for(int i:t)cout<<i<<",";
    cout<<endl;
}
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @param m long长整型 
     * @return long长整型vector
     */
    vector<long> FarmerNN(int n, long long m) {
        // write code here
        vector<long> res;
        for(int i=0;i<n;i++){
            if(i==0||i==n-1)res.push_back(1);
            else res.push_back(2);
        }
        long t = m/(2*(n-1)),k = m%(2*(n-1)),K=0;
        for(int i=0;i<n;i++){
            res[i]*=t;
        }
        for(int i=0;i<n;i++){
            if(K==k)break;
            res[i]++;
            K++;
        }
        for(int i=n-2;i>0;i--){
            if(K==k)break;
            res[i]++;
            K++;
        }
        return res;
    }
};

int main(){
    int n = 4;
    long long m = 6;
    Solution s;
    vector<long> res = s.FarmerNN(n,m);
    print(res);
    return 0;
}