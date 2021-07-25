#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> ddj(N),ddy(N);
    for(int i=N-1;i>=0;i--){
        int t;
        cin>>t;
        ddj[i] = t;
    }
    for(int i=N-1;i>=0;i--){
        int t;
        cin>>t;
        ddy[i] = t;
    }
    unordered_map<int,int> map;
    vector<int> table;
    while (true)
    {
        if(ddj.size()==0&&ddy.size()==0)break;
        if(ddj.size()>0){
            table.push_back(ddj.back());
            ddj.pop_back();
        }
        if(map[table.back()]){
            while (table.back())
            {
                /* code */
            }
            
        }
    }
    
}