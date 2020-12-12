#include<iostream>
#include<vector>

using namespace std;

void print(vector<int>&arr){
    for(int a:arr){
        cout<<a<<",";
    }
    cout<<endl;
}

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        if(B.size()>0&&m>0){
            for(int i=0;i<m;i++){
                A[i+A.size()-m] = A[i];
            }
        }
        int tmp = 0;
        int i=A.size()-m,j=0;
        // cout<<m<<B.size()<<(i<A.size())<<(j<B.size())<<endl;
        while(m&&B.size()&&i<A.size()&&j<B.size()){
            if(A[i]<B[j]){
                A[tmp] = A[i];
                i++;
            }else{
                A[tmp] = B[j];
                j++;
            }
            tmp++;
            // cout<<"tmp="<<tmp<<",i="<<i<<",j="<<j<<endl;
        }
        if (j==B.size())
        {
            while(i<A.size()){
                A[tmp] = A[i];
                i++;
                tmp++;
            }
            
        }
        if(i==A.size()||m==0){
            while(j<B.size()){
                A[tmp] = B[j];
                j++;
                tmp++;
            }
        }
    }
};

int main(){
    vector<int> a = {4,0,0,0,0,0};
    vector<int> b = {1,2,3,5,6};
    int m=1,n = 1;
    Solution s = Solution();
    s.merge(a,m,b,n);
    print(a);
    return 0;
}