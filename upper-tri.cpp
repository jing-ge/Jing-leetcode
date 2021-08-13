#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>> &arr){
    int n = arr.size();
    for(int N=0;N<n;N++){
        int i=0;
        for(int j=i+N;j<n;j++){
            cout<<i<<","<<j<<endl;
            i++;
        }
    }
    return ;
}

int main(){
    vector<vector<int>> d = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    print(d);
    return 0;
}