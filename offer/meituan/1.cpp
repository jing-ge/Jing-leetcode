#include <iostream>
#include <vector>

using namespace std;

int res = INT32_MAX;

void helpre(vector<int>&data,int idx,int k){
    cout<<"-----------"<<endl;
    cout<<idx<<endl;
    for(int j=1;j<=k;j++){
        if(idx-j>=0&&data[idx-j]!=0){
            cout<<data[idx-j]<<endl;
            res = min(res,data[idx-j]);
        }
        if(idx+j<(int)data.size()&&data[idx+j]!=0){
            cout<<data[idx+j]<<endl;
            res = min(res,data[idx+j]);
        }
    }
}

int main(){
    int n,k;
    cin>>n>>k;
    int tmp;
    vector<int> data;
    for(int i=0;i<n;i++){
        cin>>tmp;
        data.push_back(tmp);
    }
    for(int i=0;i<n;i++){
        if(data[i]==0)helpre(data,i,k);
    }
    cout<<res<<endl;
    return 0;
}