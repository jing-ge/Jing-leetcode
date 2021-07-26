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
    int cddj = 0,cddy = 0;
    while (ddj.size()>0||ddy.size()>0)
    {
        if(ddj.size()>0){
            int t = ddj[ddj.size()-1];
            ddj.pop_back();
            if(map[t]){
                while (table.size()>0&&table[table.size()-1]!=t)
                {
                    table.pop_back();
                    cddj++;
                }
                cddj+=2;
                if(ddj.size()>0){
                    t = ddj[ddj.size()-1];
                    ddj.pop_back();
                    tab
                }
            }

        }
        if(map[table.back()]){
            while (table.back())
            {
                /* code */
            }
            
        }
    }
    
}