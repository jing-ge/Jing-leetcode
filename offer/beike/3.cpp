#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_set>

using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param a int整型vector 
     * @param t int整型 
     * @return long长整型
     */
    long long section(vector<int>& a, int t) {
        int n = a.size();
        long long res = 0;
        int start = -1,end;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((a[i]^a[j])==t){
                    if(start==-1)start = i;
                    end = j;
                    int t = j-i;
                    res+=t*(t+1)/2-1;
                }
            }
        }
        if(start!=-1&&start!=0){
            int t = start;
            res+=t*(t+1)/2;
        }

        if(end!=n-1){
            int t = n-1-end;
            res+=t*(t+1)/2;
        }
        return res;
    }
};

int main(){
    vector<int> a = {2,3,4};
    int t = 6;
    Solution s;
    long long res = s.section(a,t);
    cout<<res<<endl;
    return 0;
}