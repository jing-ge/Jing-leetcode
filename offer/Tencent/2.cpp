#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double compute(int l,int r,int k){
    double res = 0.0;
    for(int i=l;i<=r;i++){
        res += pow(i+pow(10,-k),1.0/3.0)-pow(i,1.0/3.0);
    }
    return res;
}

int main(){
    int T;
    cin>>T;
    vector<double> res;
    int l,r,k;
    for(int i=0;i<T;i++){
        cin>>l>>r>>k;
        res.push_back(compute(l,r,k));
    }
    for(int i=0;i<T;i++){
        cout<<res[i]<<endl;
    }
    return 0;
}