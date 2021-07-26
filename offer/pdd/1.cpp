#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isinclude(vector<vector<int>> &data){
    int n = data.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(data[i][0]<=data[j][0]&&data[i][1]>=data[j][1])return true;
            if(data[i][0]>=data[j][0]&&data[i][1]<=data[j][1])return true;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> data;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        data.push_back({a,b});
    }
    bool res = isinclude(data);
    if(res){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}