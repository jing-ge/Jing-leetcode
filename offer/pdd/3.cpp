
#include <iostream>
#include <vector>

using namespace std;


bool isset(int A,int B,int C,int Q){
    if(Q<1)return false;
    if(Q==A)return true;
    if(Q%C==0){
        return isset(A, B, C, Q-B)||isset(A, B, C, Q/C);
    }else{
        return isset(A, B, C, Q-B);
    }
    return true;
}

bool isset2(int A,int B,int C,int Q){
    vector<int> data;
    data.push_back(A);
    int p1=0,p2=0;
    while(true){
        int m1 = data[p1]+B,m2 = data[p2]*C;
        int t = min(m1,m2);
        if(t==m1){
            p1++;
        }
        if(t==m2){
            p2++;
        }
        // cout<<t<<endl;
        data.push_back(t);
        if(t==Q)return true;
        if(t>Q)return false;
    }
    return false;
}

int main(){
    int T;
    cin>>T;
    vector<bool>ress;
    for(int i=0;i<T;i++){
        int A,B,C,Q;
        cin>>A>>B>>C>>Q;
        bool res = isset2(A,B,C,Q);
        ress.push_back(res);
    }
    for(bool i:ress){
        cout<<i<<endl;
    }
    // cout<<isset2(2,3,2,10)<<endl;
    return 0;
}